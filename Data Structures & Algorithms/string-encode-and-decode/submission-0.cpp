class Solution {
public:

    string encode(vector<string>& strs) {
    if (strs.empty()) return "";

    vector<int> sizes;
    string str;

    for (string s : strs)
        sizes.push_back(s.size());

    for (int sz : sizes) {
        str.append(to_string(sz));
        str.push_back(',');
    }

    str.push_back('#');

    for (string s : strs) {
        str.append(s);
    }

    return str;
}


    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<int> sizes;
        vector<string> res;
        
        int i = 0;
        while(s[i] != '#'){
            int j = i;

            while(s[j] != ',')j++;
            sizes.push_back(stoi(s.substr(i, j-i)));
            i = j+1;
        }
        // for(int a:sizes)cout<< a << endl;
        // cout << 111<<endl;
        i++;

        for(int x:sizes){
            res.push_back(s.substr(i, x));
            i+=x;
        }

        for(string sb: res)cout<< sb << " ";

        return res;
    };
};
