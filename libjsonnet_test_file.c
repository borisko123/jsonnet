/*
Copyright 2014 Google Inc. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdlib.h>
#include <stdio.h>

#include "libjsonnet.h"

int main(int argc, const char **argv)
{
    const char *error = NULL;
    const char *json;
    if (argc != 2) {
        fprintf(stderr, "libjsonnet_test_file <file>\n");
        return EXIT_FAILURE;
    }
    json = jsonnet_evaluate_file(argv[1], &error);
    if (json == NULL) {
        fprintf(stderr, "%s", error);
        jsonnet_delete(error);
        return EXIT_FAILURE;
    } 
    printf("%s", json);
    jsonnet_delete(json);
    return EXIT_SUCCESS;
}
