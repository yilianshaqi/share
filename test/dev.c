/*************************************************************************
    > File Name: dev.c
    > Author: huang yang
    > Mail: huangyangwork@sina.com 
    > Created Time: 2016年11月21日 星期一 19时20分30秒
 ************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/poll.h>
//模块加载
  //驱动号申请
  //设备初始化
  //设备注册
//设备操作集功能的实现
  //open
  //close
  //write
	//有数据可读时唤醒
  //read
	//没有数据可读时阻塞
  //fcntl
    //异步通知设定
  //poll
//模块卸载
  //设备注销
  //设备号注销
#define DEV_MAJOR  199
#define DEV_MINOR  512
#define DEV_COUNT  5
#define BUF_SIZE   100
struct cdev  mycdev;
struct class *myclass=NULL;
struct device *mydevice=NULL;
int source_count=0;
wait_queue_head_t my_queue;
char buf[BUF_SIZE]="";






static int my_open(struct inode *inode, struct file *file)
{
	printk("open ok\n");
	return 0;
}

static int my_close(struct inode *inode, struct file *file)
{
	printk("close file\n");
	return 0;
}

ssize_t my_read (struct file *file, char __user *to, size_t len, loff_t *pos)
{
	if(file->f_flags & O_NONBLOCK )
	{
		if(source_count<=0)
		{
			return -EAGAIN;
		}
	}
	else 
	{
		if(source_count<=0)
		{
			printk("wait_event\n");
			wait_event(my_queue,source_count>0);
		}
	}
	if(source_count<len)
	{
		copy_to_user(to,buf,source_count);
		return source_count;
	}
	else{
		copy_to_user(to,buf,len);
		return len;
	}
}

ssize_t my_write (struct file *file, const char __user *from, size_t len, loff_t *pos)
{
	printk("write ok\n");

	copy_from_user(buf,from,len);
	source_count+=len;
	if(source_count>0)
	{
		wake_up(&my_queue);
	}
	return len;
}

int dev_module_init(void)
{
	int ret;

	struct file_operations operate={
	.owner = THIS_MODULE,
	.open=my_open,
	.release=my_close,
	.write=my_write,
	.read=my_read,
	};
	ret=register_chrdev_region(MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT,"test_dev");
	if(ret<0)
	{
		printk("request failer\n");
		return -1;
	}
	cdev_init(&mycdev,&operate);
	cdev_add(&mycdev,MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT);
	printk("init ok\n");
/*
	//自动创建设备
	myclass=class_create(THIS_MODULE,"test_dev");
	if(IS_ERR(myclass))
	{
		ret = PTR_ERR(myclass);
		goto DEV_DESTROY;
	}
	mydevice = device_create(myclass,NULL,MKDEV(DEV_MAJOR,DEV_MINOR),NULL,"test_dev_only");
	if(NULL==mydevice)
	{
		printk("device create error\n");
		goto CLASS_DESTROY;
	}
	
	init_waitqueue_head(&my_queue);
	CLASS_DESTROY:
		class_destroy(myclass);
	DEV_DESTROY:
		cdev_del(&mycdev);
		unregister_chrdev_region(MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT);  */
		return ret;  
}


void dev_module_exit(void)
{
//	device_destroy(myclass,MKDEV(DEV_MAJOR,DEV_MINOR));
//	class_destroy(myclass);
	cdev_del(&mycdev);
	unregister_chrdev_region(MKDEV(DEV_MAJOR,DEV_MINOR),DEV_COUNT);

}
MODULE_LICENSE("GPL");
module_init(dev_module_init);
module_exit(dev_module_exit);
