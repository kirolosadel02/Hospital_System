#include <bits/stdc++.h>
using namespace std;

struct Patients{
    int specialization{};
    string name;
    string status;
};
vector<deque<Patients>>patient(20);
int menu(){
    cout<<"1) Add new patient\n";
    cout<<"2) Print all patients\n";
    cout<<"3) Get next patient\n";
    cout<<"4) Exit\n";
    int n;
    cin>>n;
    return n;
}
void AddNewPatient(){
    cout<<"Enter specialization,name,status\n";
    int specialization;
    string name;
    int status;
    cin>>specialization>>name>>status;
    if(patient[specialization].size() >=5){
        cout<<"Sorry we can't add more patients for this specialization\n";
    }
    else {
        if (status == 1) {
            patient[specialization].emplace_front() = {specialization, name, "urgent"};
        } else
            patient[specialization].emplace_back() = {specialization, name, "regular"};
    }
}
void PrintAllPatients(){
    bool there_are_patients = false;
    for (int i = 0; i < 20; ++i) {
        if(!patient[i][0].name.empty()) {
            cout << "There are " << patient[i].size() << " in specialization " << i << '\n';
            for (int j = 0; j < 5; ++j) {
                if (!patient[i][j].name.empty())
                    cout << patient[i][j].name << ' ' << patient[i][j].status << '\n';
            }
            there_are_patients = true;
            cout<<"========================================="<<'\n';
        }
    }
    if(!there_are_patients)
        cout<<"There are no patients"<<'\n';
}
void GetNextPatient(){
    cout<<"Enter Specialization: ";
    int num;
    cin>>num;
    if(!patient[num].front().name.empty()){
        cout<<patient[num].front().name<<" please go with the Dr"<<'\n';
        patient[num].pop_front();
    }
    else
        cout<<"No patients at the moment. Have a rest, Dr"<<'\n';
}
void HospitalSystem(){
    while(true) {
        int choice = menu();
        if (choice == 1)
            AddNewPatient();
        else if (choice == 2)
            PrintAllPatients();
        else if(choice ==3)
            GetNextPatient();
        else
            break;
    }
}

int main(){
    HospitalSystem();
}