#include <iostream>
using namespace std;

class SingletonPattern { // Where only one instance of a class can be created (Multiple objects can be created still all pointing to the same instance)
   private:
      static SingletonPattern *instance;
      int data;
   
      SingletonPattern() { // Private constructor so that no objects can be created.
         data = 0;
      }

   public:
      static SingletonPattern *getInstance() {
         if (!instance) {
            if (!instance) {
               instance = new SingletonPattern;
            }
         }
         return instance;
      }

      int getData() { // Getter
         return this->data;
      }

      void setData(int data) { // Setter
         this->data = data;
      }
};

SingletonPattern *SingletonPattern::instance = 0; //Initialize pointer to zero so that it can be initialized in first call to getInstance

int main() {
   SingletonPattern *s1 = s1->getInstance(); // Two objects
   SingletonPattern *s2 = s2->getInstance();
   s1->setData(100);
   cout << s1->getData() << endl; // Outputs 100
   cout << s2->getData() << endl; // Also outputs 100 despite only s1 being set to 100
   return 0;
}