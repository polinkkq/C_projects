#include <stdio.h>
#include <sqlite3.h>
int main(){
	sqlite3 * db;
	char * err_msg = 0;
	int rc = sqlite3_open("database.db", &db);
	if (rc != SQLITE_OK){
		printf("Error");
		sqlite3_close(db);
		return 1;
	}
	char * sql = "DROP TABLE IF EXISTS people;"
				"CREATE TABLE people(id_people INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER);"
				"INSERT INTO people(name, age) VALUES ('Tom', 38)";
	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
	if (rc != SQLITE_OK )
	{
		printf("SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);      // очищаем ресурсы
		sqlite3_close(db);
		return 1;
	}
	sqlite3_close(db);
	printf("Table created\n");
}
