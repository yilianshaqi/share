package com.farsight.read;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Readfile
{
	public static void main(String[] args)
	{
		byte[] str = new byte[5];                
		File fd = new File("D://test.jpg"); //打开输入文件流
		File sfd= new File("C://test");   //打开输出文件流
		int ret;
		try
		{
			FileInputStream rfd = new FileInputStream(fd);   //创建输入字节流
			FileOutputStream wfd = new FileOutputStream(sfd);//创建输出字节流
			try
			{
				while ((ret=rfd.read(str)) != -1)  //循环读取字节
				{
					wfd.write(str, 0, ret);//写入字节
					
				}
			} catch (IOException e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println("操作完成！");

		} catch (FileNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
