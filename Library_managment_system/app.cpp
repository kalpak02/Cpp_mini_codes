// Library managment system   ///error

#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<algorithm>

using  namespace std;
 
class LibraryItem{
       protected:
         string title;
         string author;

        public:
          LibraryItem(const string& title,const string& author):
          title(title),author(author){}

          virtual void display()const =0;
           virtual ~LibraryItem(){}
};

class Book: public LibraryItem{
          private:
            string ISBN;

        public:
           Book(const string& title,const string& author,const string& ISBN):
             LibraryItem(title, author),ISBN(ISBN){}

               void display()const override{
                     cout<<"BOOK"<<title<<"by"<<author<<"ISBN"<<ISBN<<endl;

               }



};



class Magazine: public LibraryItem{
        private:
         int issue;
        public:
          Magazine(const string& title,const string& author,int issue):
              LibraryItem(title,author),issue(issue){}

         void display()const override{
               cout<<"Magazine"<<title<<"by"<<author<<"issue"<<issue<<endl;
         } 


};

class Library{
      private:
        vector<shared_ptr<LibraryItem>>items;
        
    public:
   
      void addItem(const shared_ptr<LibraryItem>&item){
          items.push_back(item);
      }

      void displayAll() const{
            cout<<"\n   LIBRARY CATALOG\n";
            for(const auto&item: items){
                 item->display();
            }
      }
};


int main(){
       Library a;
       a.addItem(make_shared<Book>("The Alchemist","paulo coelho","889-0061122315"));
       a.addItem(make_shared<Magazine>("Fobes","Editorial",12));
        
       a.displayAll();
       return 0;
}
