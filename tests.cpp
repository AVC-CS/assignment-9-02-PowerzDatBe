// Test definitions. Do NOT edit this file!
#define CATCH_CONFIG_MAIN // defines main() automatically
#include <iostream>
#include "catch.hpp"
#include "main.hpp"
// tests for exercise 1

TEST_CASE("Ex1 ", "[example]")
{
	Student *head, *tmp;

	head = makeStudent();
	printStudent(head);

	tmp = head;
	REQUIRE(tmp->id == 10001);
	REQUIRE(strcmp(tmp->name, "John") == 0);
	REQUIRE(strcmp(tmp->major, "Math") == 0);

	tmp = tmp->next;
	REQUIRE(tmp->id == 10002);
	REQUIRE(strcmp(tmp->name, "James") == 0);
	REQUIRE(strcmp(tmp->major, "Physics") == 0);

	tmp = tmp->next;
	REQUIRE(tmp->id == 10003);
	tmp = tmp->next;
	REQUIRE(tmp->id == 10004);
	tmp = tmp->next;
	REQUIRE(tmp->id == 10005);
	cout << "--------------------------------------------------\n";
	cout << "--------------------------------------------------\n";
}