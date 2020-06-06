void extraLongFactorials(int n) {
    vector<int> bigInt(1, 1);
    int carry = 0;
    for(int num = 2;num <= n; ++num) {
        for(int i = 0; i < bigInt.size(); ++i) {
            int prod = bigInt[i]*num + carry; 
            bigInt[i] = prod%10;
            carry = prod/10;
        }   

        while(carry) {
            bigInt.push_back(carry%10);
            carry/=10;
        }
    }

        for(int i = bigInt.size()-1; i >= 0; --i) {
            cout<<bigInt[i];
        }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
