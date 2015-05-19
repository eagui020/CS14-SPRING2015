A)  No, the sort is not stable. The use of swap without something in place to
    keep track of priority will cause any value that was before an
    identical to be placed behind it if it is swapped with a smaller value that
    is in a position after the identical.
    
B)  vector<pair<int, int> > stableTest;
    stableTest.push_back(make_pair(-1, 3));
    stableTest.push_back(make_pair(-1, 3));
    stableTest.push_back(make_pair(-2, 3));
    //moves should be 6 as two swaps are needed to make sure the first pair of
    //(-1,3) is in front of the 2nd
    cout << "pre:\t";
    for (auto i = stableTest.begin(); i != stableTest.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl;
    selectionsort(stableTest);
    cout << "post:\t";
    for (auto i = stableTest.begin(); i != stableTest.end(); ++i)
    {
        cout << "(" << i->first << "," << i->second << ") ";
    }
    cout << endl << endl;