void seperateString() {
    const char* d = "";
    char* p;
    p = strtok(data, d);
    while (p != NULL) {
        if (check == 0) {
            N = atoi(p);
            check += 1;
        } else {
            O = atoi(p);
        }
        p = strtok(NULL, d);
    }
}