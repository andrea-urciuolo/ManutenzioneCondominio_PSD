#ifndef TESTINGBTREE_H
#define TESTINGBTREE_H

int run_test_suite_newBtree(const char* input_path, const char* oracle_path);
int run_test_suite_emptyBtree(const char* input_path, const char* oracle_path);
int run_test_suite_insertTechnician(const char* input_path, const char* oracle_path);
int run_test_suite_sizeBtree(const char* input_path, const char* oracle_path);
int run_test_suite_clearTreeNodes(const char* input_path, const char* oracle_path);

#endif