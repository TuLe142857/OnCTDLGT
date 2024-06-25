for(int i = 10; i <= 1000000; i *= 10){
        MAX_MEMORY = i;
        TestExternalSorting("10tr.txt", "10tr_out.txt");
        cout << endl;
    }

    TestExternalSorting("100tr.txt", "100tr_out.txt");
    cout << endl;