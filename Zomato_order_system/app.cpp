//zomato order system    //Done 

#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<string>
  

using namespace std;

class Dish{
        protected:
           string name;
           double price;

        public:
          Dish(const string& name,double price):name(name),price(price){}
           virtual void display()const =0;
           virtual double getPrice()const =0;
           virtual ~Dish(){}
};

//inherited class 
 class VegDish:public Dish{
       public:
         VegDish(const string& name,double price):Dish(name,price){}
         void display()const override{
                 cout<<"[veg]"<<name<<" -Rs"<<price<<".\n";

         }

         double getPrice()const override{ return price;} 
        
};

class NonVegDish:public Dish{
         public:
            NonVegDish(const string& name, double price):Dish (name,price){}

            void display()const override{
                   cout<<"[NoN Veg]"<<name<< "-Rs"<<price<<".\n";

            }
            double getPrice() const override{ return price;}
};


class order{
        private: 
          vector<shared_ptr<Dish>>dishes;
          int orderId;

        public:
          order(int id): orderId(id){}

          void addDish(shared_ptr<Dish>dish){
             dishes.push_back(dish);
          }

          void showBill()const {
               cout<<"\nOrder ID:"<<orderId<<".\n";
               double total= 0;
               for(auto& dish:dishes){
                   dish->display();
                   total+= dish->getPrice();
               }
               cout<<"Total Price:"<<total<<endl;
          }

};


int main(){
       order order1(1001);
       
       shared_ptr<Dish> D1 =make_shared<VegDish>("Palak panner",183);
       shared_ptr<Dish> D2 =make_shared<NonVegDish>("Biryani",250);

       order1.addDish(D1);
          order1.addDish(D2);

          order1.showBill();

          return 0;



}