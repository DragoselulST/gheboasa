#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <math.h>

class Automobil{
  
  protected: 
  std::string tip;
  std::string nume;
  int capacitate;
  int viteza_medie;
  
  public:
  
  Automobil(){}
  
  Automobil(std::string tip, std::string nume, int capacitate, int viteza_medie):tip(tip), nume(nume), capacitate(capacitate), viteza_medie(viteza_medie){}

    int get_viteza_medie(){
        return this->viteza_medie;
    }
    
  virtual void afisare(){}
  
  virtual void grup(int x){}
  
  virtual void grup_cu_rest(int x){}
  
  virtual void durata_drum(float x, int y){}
  
}; 
  class Masina: public Automobil{
  
    public: 
    
    Masina(){}
    
    Masina(std::string tip, std::string nume, int capacitate, int viteza_medie) :Automobil(tip,nume,capacitate,viteza_medie){}
    
    void afisare(){
     std::cout<<nume<<"\n"<<capacitate<<"\n"<<viteza_medie<<std::endl;   
    }
    
    void grup(int x){
        std::cout<<nume<<"\n"<<x/capacitate<<std::endl;
    }
    void grup_cu_rest(int x){
        std::cout<<nume<<"\n"<<x/capacitate+1<<std::endl;
    }
    
    void durata_drum(float x, int y){
        std::cout<<nume<<"\n"<<std::fixed<<std::setprecision(2)<<x/viteza_medie<<std::endl;
    }
    
  };
  
  class Autocar : public Automobil{

      public:
      
      Autocar(){}
      
      Autocar(std::string tip, std::string nume, int capacitate, int viteza_medie) : Automobil(tip,nume,capacitate,viteza_medie){}
      
      void afisare(){
          std::cout<<nume<<"\n"<<capacitate<<"\n"<<viteza_medie<<std::endl;
      }
      void grup(int x){
        std::cout<<nume<<"\n"<<x/capacitate<<std::endl;
    }
    void grup_cu_rest(int x){
        std::cout<<nume<<"\n"<<x/capacitate+1<<std::endl;
    }
    void durata_drum(float x, int y){
        std::cout<<nume<<"\n"<<std::fixed<<std::setprecision(2)<<x/viteza_medie<<std::endl;
    }
  };
  
  
  
    



int main(){
    
    std::string tip;
    std::string nume;
    int capacitate;
    int viteza_medie;


    int optiune;
    std::cin>>optiune;
    
    int n;
    std::cin>>n;
    
    Automobil **automobil_array = nullptr;
    automobil_array = new Automobil*[n];
    
    int k=0;
    
    for(int i=0; i<n; i++){
        std::cin>>tip;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, nume);
        std::cin>>capacitate;
        std::cin>>viteza_medie;
        
        if(tip == "Masina"){

            *(automobil_array + (k++)) = new Masina(tip, nume, capacitate, viteza_medie);
        }
        if(tip == "Autocar"){

            *(automobil_array + (k++)) = new Autocar(tip, nume, capacitate, viteza_medie);
        }
    }
    

    
    if(optiune == 1){

        for(int i=0; i<n; i++){
            (*(automobil_array + i))->afisare();
        }
    }
    
    if(optiune ==2){
        
        int x;
        std::cin>>x;
        
        for(int i=0; i<n; i++){
            if(x%capacitate == 0){

        (*(automobil_array + i))->grup(x);
            }
             if(x%capacitate != 0){

        (*(automobil_array + i))->grup_cu_rest(x);
            }
            
        }
    }
    
    if(optiune == 3){
        
        float lungime_drum;
        int limita_timp;
        
        std::cin>>lungime_drum;
        std::cin>>limita_timp;
        
        for(int i=0; i<n; i++){
            if(lungime_drum/(*(automobil_array + i))->get_viteza_medie() < limita_timp){
                (*(automobil_array + i))->durata_drum(lungime_drum, limita_timp);
            }

        }
    }
    
    
    return 0;
}