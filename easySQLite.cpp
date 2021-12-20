// easySQLite.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "easySQLite/SqlCommon.h"
#include "easySQLite/SqlField.h"
#include "easySQLite/SqlDatabase.h"
#include "easySQLite/SqlTable.h"

#include "UnitTest++/src/UnitTest++.h"
#include "opt/public.h"
#include <thread>

using namespace sql;


//define table structure
Field definition_tbKLine_M1[] = 
{
	Field(FIELD_KEY),
//	Field("symbol", type_text, flag_not_null),
//	Field("time", type_int, flag_not_null),
//	Field("open", type_float, flag_not_null),
//	Field("low", type_float, flag_not_null),
//	Field("high", type_float, flag_not_null),
//	Field("close", type_float, flag_not_null),
	Field("vol", type_int, flag_not_null),
	Field(DEFINITION_END),
};


enum class tets_mode
{
	t_insert,
	t_delete,
	t_update,
	t_search
};

 

// ret : delay_ms   -1: error
int  sqlite_test1(bool mem_type, bool one_commmit, tets_mode mode, int test_count )
{
	int delay_ms = 0;
	//define database object
	sql::Database db;
	try
	{
		//open database file

		if(mem_type)
			db.open(":memory:");
		else
			db.open("test.db"); 
		
		//define table object
		Table tbKLine(db.getHandle(), "person", definition_tbKLine_M1);

		//remove table from database if exists
		if (tbKLine.exists())
		{
			if(mem_type)
			{
				tbKLine.remove();
				sql::log(" remove all tables  " + tbKLine.name());
			}
		}
		else
		{
			//create new table
			tbKLine.create();
		}
		


		//define new record
		Record record(tbKLine.fields());

		//set record data
//		record.setString("symbol", "600519");
//		record.setInteger("time", 211216094501);
//		record.setDouble("open", 1500.0);
//		record.setDouble("low", 1500.0);
//		record.setDouble("high", 1500.0);
//		record.setDouble("close", 1500.0);
		record.setInteger("vol", 5000);

		diff_count  diff_insert;
		diff_insert.start();
//------------------


		switch (mode)
		{
		case tets_mode::t_insert :

				if(one_commmit)
				{
					if(db.transactionBegin())
					{
						for(int i = 0 ; i < test_count; i++)
						{
							record.setInteger("vol", i);
							tbKLine.addRecord(&record);
						}
						db.transactionCommit();
					}
				}
				else
				{					
					{
						for(int i = 0 ; i < test_count; i++)
						{
							record.setInteger("vol", i);
							tbKLine.addRecord(&record);
						}
					}			
				}	
			break;

		case tets_mode::t_delete :
			
			break;

		case tets_mode::t_update :
			
			break;
		case tets_mode::t_search :
			
			break;

		default:
			break;
		}





		//list loaded records
		#if 0
		for (int index = 0; index < tbPerson.recordCount(); index++)
			if (Record* record = tbPerson.getRecord(index))
				sql::log(record->toString());
		#endif

		
//------------------
		diff_insert.add_snap();
		delay_ms = diff_insert.show_diff();

		tbKLine.open();
		sql::log( " delay=" + sql::intToStr(delay_ms) +  "  , op id :" + intToStr(int(mode)) + " , handle item count = " + sql::intToStr(test_count) + ",  totle item:" + sql::intToStr(tbKLine.recordCount()) );

		//sql::log(" delay=");
		//sql::log(sql::intToStr(delay_ms));
		//sql::log("ALL OK");

	} catch (Exception e) {
		printf("ERROR: %s\r\n", e.msg().c_str());
		return -1;
	}

	return delay_ms;
}

void example2()
{
	Field definition_tbTest[] = 
	{
		Field(FIELD_KEY),
		Field("name", type_text, flag_not_null),
		Field("valueInt", type_int),
		Field("valueDbl", type_float),
		Field("valueTxt", type_text),
		Field("valueBol", type_bool, flag_not_null),
		Field("valueTme", type_time),
		Field(DEFINITION_END),
	};

	Database db;

	try
	{
		db.open("test.db");

		Table source(db.getHandle(), "tbTest", definition_tbTest);

		if (source.exists())
			source.remove();

		source.create();

		for (int index = 0; index < 5; index++)
		{
			Record record(source.fields());

			record.setString("name", "test_name_1");
			record.setInteger("valueInt", 1234567890);
			record.setDouble("valueDbl", 12345.67890);
			record.setString("valueTxt", "test'value'1");
			record.setBool("valueBol", true);
			record.setTime("valueTme", time::now());

			source.addRecord(&record);
		}

		if (Table* target = Table::createFromDefinition(db.getHandle(), "_backup_" + source.name(), source.fields()->getDefinition()))
		{
			if (target->backup(source))
			{
				sql::log("");
				sql::log("ALL OK");
			} else {
				sql::log(source.errMsg());
				sql::log(target->errMsg());
			}

			delete target;
		}
	} catch (Exception e) {
		printf("ERROR: %s\r\n", e.msg().c_str());
	}
}


int main(int argc, char* argv[])
{
	int ret =sqlite_test1(true,true, tets_mode::t_insert, 100*10000);
 

	sql::log(" test result: " + intToStr(ret));

//	return UnitTest::RunAllTests();
}
