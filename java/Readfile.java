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
		File fd = new File("D://test.jpg"); //�������ļ���
		File sfd= new File("C://test");   //������ļ���
		int ret;
		try
		{
			FileInputStream rfd = new FileInputStream(fd);   //���������ֽ���
			FileOutputStream wfd = new FileOutputStream(sfd);//��������ֽ���
			try
			{
				while ((ret=rfd.read(str)) != -1)  //ѭ����ȡ�ֽ�
				{
					wfd.write(str, 0, ret);//д���ֽ�
					
				}
			} catch (IOException e)
			{
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println("������ɣ�");

		} catch (FileNotFoundException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
