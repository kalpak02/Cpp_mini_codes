
//student management system    //bugs hai!! will  solve later


#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<algorithm>

using namespace std;

class person{
      protected :
         string name;
         int age;
     
     public:
       person (const string& name,int age):name(name),age(age){}
       virtual void display()const =0;
       virtual ~person(){};     
};

class student: public person{
      private :
       int rollNumber;
       string course;
        
     public:
         student(const string& name,int age,int rollNumber,string & course):
          person(name,age),rollNumber(rollNumber),course(course){}
        
           void display() const override{
                cout<<"Name"<<name<<"Age"<<age<<"Roll Number"<<rollNumber<<"Course"<<course<<"\n";
           }

           int getRollNumber()const { return rollNumber; }


}; 

class StudentManager{
         private:
            vector<shared_ptr<student>>students;  ///SHAERED Ptr cONCEPT
        public:
           void addStudent(const string & name,int age,int roll, const string& course){  ////explaintin neede ki bina const keyword ke kyu work nahi karega
              students.push_back(make_shared<student>(name,age,roll,course));
           }

           void removeStudent(int roll){
                 
                  students.erase(
                     remove_if(students.begin(),students.end(),[roll](const shared_ptr<student>&s){  //shared_ptr concept
                        return s->getRollNumber()==roll;
                    }),
                 
                     students.end()
                  );
           }

           void displayAll()const {
             if(students.empty()){
                  cout<<"No student in the system.\n";
                  return;
                
             }
             for(const auto & s:students){
                  s->display();
             }
           }
};



int main(){
     StudentManager manager;
    manager.addStudent("kalpak",20,2018,"computer science");
    manager.addStudent("sujal",20,2033,"computer science");

    cout<<"All students.\n";
    manager.displayAll();

    cout<<"\nRemoving student with roll 2018... ";
    manager.removeStudent(2018);

    cout<<"\nAll students\n ";
    manager.displayAll();

    return 0;


}
