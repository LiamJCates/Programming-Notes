/**
Licensed to the Apache Software Foundation (ASF) under one or more
contributor license agreements.  See the NOTICE file distributed with
this work for additional information regarding copyright ownership.
The ASF licenses this file to You under the Apache License, Version 2.0
(the "License"); you may not use this file except in compliance with
the License.  You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package com.pluralsight.corejdbc.m3c3;

import java.sql.Connection;

import javax.naming.InitialContext;
import javax.sql.DataSource;

public class ProductsComponent_JNDI{
	
	public boolean getProductCount() throws Exception{
		
		InitialContext ctx = new InitialContext();

        DataSource dataSource = (DataSource)ctx.lookup("jdbc/mysql"); 

        Connection connection = dataSource.getConnection("genius", "abracadabra");
		
		boolean isValid = connection.isValid(2);
		
		connection.close();
		
		return isValid;
	
	}
}
