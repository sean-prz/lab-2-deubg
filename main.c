//
// Created by Sean Perazzolo on 02.04.2025.
//
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE, etc.

// Include the headers for the components you want to test
#include "inc/buffer_manager.h"
#include "inc/replacer.h"
#include "inc/storage_manager.h"
#include "inc/bp_error.h"
// #include "config.h" // Include if needed directly
// #include "page.h"   // Include if needed directly

// --- Add your test functions here ---
// Example:
void test_buffer_manager() {
    printf("Testing Buffer Manager...\n");
    printf("Buffer Manager tests finished.\n\n");
}

void test_replacer() {
    printf("Testing Replacer...\n");

}

void test_replacer2() {

}

void test_storage_manager() {
    printf("Testing Storage Manager...\n");
    printf("Storage Manager tests finished.\n\n");
}


// --- Main function to run tests ---
int main() {
    printf("--- Starting Project Tests ---\n\n");

    test_buffer_manager();
    test_replacer();
    test_replacer2();
    test_storage_manager();
    // Add calls to other test functions

    printf("--- All Tests Completed ---\n");
    return EXIT_SUCCESS; // Or EXIT_FAILURE if any test fails
}
