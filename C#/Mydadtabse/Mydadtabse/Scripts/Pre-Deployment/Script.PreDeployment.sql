﻿/*
 预先部署脚本模板							
--------------------------------------------------------------------------------------
 此文件包含将在生成脚本前执行的 SQL 语句	
 使用 SQLCMD 语法将文件包含在预先部署脚本中			
 示例:      :r .\filename.sql								
 使用 SQLCMD 语法引用预先部署脚本中的变量		
 示例:      :setvar TableName MyTable							
               SELECT * FROM [$(TableName)]					
--------------------------------------------------------------------------------------
*/