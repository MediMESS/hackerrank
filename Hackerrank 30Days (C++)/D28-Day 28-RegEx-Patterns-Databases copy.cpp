#include <bits/stdc++.h>
#include <string.h>
#include <regex>
using namespace std;

vector<string> split_string(string);
vector<string> insert_ordered(vector<string>, string);


int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> ordered_names;
    regex regex_gmail ("([a-z]|\\.)+@gmail\\.com$");
    int j = 0;
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string firstNameEmailID_temp;
        getline(cin, firstNameEmailID_temp);

        vector<string> firstNameEmailID = split_string(firstNameEmailID_temp);

        string firstName = firstNameEmailID[0];

        string emailID = firstNameEmailID[1];
        int sizeEmail = emailID.size();
        int sizeName = firstName.size();
        // if email ends with @gmail.com && size <= 50
        
        if(regex_match(emailID, regex_gmail) && sizeEmail <= 50 && sizeName <= 20){
            ordered_names = insert_ordered(ordered_names, firstName);
            // cout << "New Vector: " << endl;
            // for(int i=0; i < ordered_names.size(); i++){
            //     cout << ordered_names[i] << ", ";
            // }
            // j++;
        }
        
    }
    
    for(int i=0; i < ordered_names.size(); i++){
        cout << ordered_names[i] << endl;
    }

    return 0;
}

vector<string> insert_ordered(vector<string> ordered_names, string name) {
    // cout << "\nINSERT ORDERED" << endl;
    if(ordered_names.size() == 0){
        // cout << "SIZE == 0, Inserting: " << name << endl;
        ordered_names.push_back(name);
        
    }else {
        // cout << "SIZE > 0, Inserting: " << name << endl;
        bool found_place = false;
        int j = 0;
        while(!found_place && j < ordered_names.size()){
            if(ordered_names[j].compare(name) > 0){
                ordered_names.insert(ordered_names.begin()+j, name);
                found_place = true;
            }
            j++;
        }
        if(found_place == false) {
            ordered_names.push_back(name);
        }
    }
    return ordered_names;
}


vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
