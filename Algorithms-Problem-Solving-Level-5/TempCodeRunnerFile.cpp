void ReadArray(int arr[100] , int& arrLength){
    cout << "Please Enter Number Of Element : " ;
    cin >> arrLength ;
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element["<< i + 1 <<"] : " ;
        cin >> arr[i];
    }
}