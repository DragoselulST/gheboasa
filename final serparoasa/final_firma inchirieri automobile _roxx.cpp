#include<iostream>
#include<string>
#include<limits>
#include<iomanip>
#include<math.h>
#include<stdio.h>
#include <bits/stdc++.h>
#include<algorithm>


class Automobil{
    
  protected:
     std:: string tip;
     std::string nume;
     int capacitate;
     float viteza_medie;
     
  public:
    
    Automobil(){}
    Automobil(std::string tip,std::string nume,int capacitate,float viteza_medie):tip(tip),nume(nume),capacitate(capacitate),viteza_medie(viteza_medie){}
    
    //getters
    std::string get_tip()
    {
        return this->tip;
    }
    std::string get_nume()
    {
        return this->nume;
    }
    int get_capacitate()
    {
        return this->capacitate;
    }
    float get_viteza_medie()
    {
        return this->viteza_medie;
    }
    
    //functii
    virtual  void afisare_1(){}
    
    virtual void grup_persoane_2(int x){}
    
    virtual void durata_drum_3(int l, int t){}
    
    virtual float poluare_4(int x){ return 0;}
    
};

class Masina:public Automobil{
  private:
    
  public:
     Masina(){}
     Masina(std::string tip,std::string nume,int capacitate,float viteza_medie):Automobil(tip,nume,capacitate,viteza_medie){}
     
     void afisare_1()
     {
         std::cout<<nume<<"\n"<<capacitate<<"\n"<<viteza_medie<<std::endl;
     }
     
     void grup_persoane_2(int x)
     {
      
         int auto_necesare=0;

             auto_necesare=x/capacitate;
            
             if(x%capacitate != 0)
             {
                 auto_necesare++;
             }
             
             std::cout<<nume<<"\n"<<auto_necesare<<std::endl;
         
         
     }
     
     void durata_drum_3(int l,int t)
     {
        float durata=0;
        
         durata= l/viteza_medie;   
         
         if(durata <= t)
         {
             std::cout<<nume<<"\n";
             std::cout<<std::fixed<<std::setprecision(2)<<durata<<std::endl; 
         }
         
     }
     
     
     float poluare_4(int x)
     {
         float coeficient=0;
         float coeficient_total=0;
         int auto_necesare=0;
        
         
          auto_necesare=x/capacitate;
          if(x%capacitate != 0)
         {
             auto_necesare++;
         }
         coeficient=viteza_medie/100+(x/auto_necesare)/capacitate;
         

        
         coeficient_total = coeficient*auto_necesare;
         
         return coeficient_total;
     }
  
};

class Autocar: public Automobil{
    
    private:
    
    public:
       Autocar(){}
       Autocar(std::string tip,std::string nume,int capacitate,float viteza_medie):Automobil(tip,nume,capacitate,viteza_medie){}
    
       void afisare_1()
       {
           std::cout<<nume<<"\n"<<capacitate<<"\n"<<viteza_medie<<std::endl;
       }
       
       void grup_persoane_2(int x)
       {
        
         int auto_necesare=0;
         
         auto_necesare=x/capacitate;
         if(x%capacitate != 0)
         {
             auto_necesare++;
         }
         
         std::cout<<nume<<"\n"<<auto_necesare<<std::endl;
         
       }
       
       void durata_drum_3(int l,int t)
       {
           float durata=0;
           durata= l/viteza_medie;   
           
           if(durata <= t)
           {
               std::cout<<nume<<"\n";
               std::cout<<std::fixed<<std::setprecision(2)<<durata<<std::endl; 
           }
   
       }
       
       float poluare_4(int x)
       {
          float coeficient=0;
          float coeficient_total=0;
          int auto_necesare=0;
          auto_necesare=x/capacitate;
          
          if(x%capacitate != 0)
          {
             auto_necesare++; 
          }
          
          coeficient=viteza_medie/20 + pow(2.71 , (((2*x)/auto_necesare)/capacitate));
          

         coeficient_total = coeficient*auto_necesare;
         return coeficient_total;
       }
};


class FirmaInchirieri : public Automobil{
   
  protected:
  
  public:
     FirmaInchirieri(){}
     FirmaInchirieri(std::string tip,std::string nume,int capacitate,float viteza_medie):Automobil(tip,nume,capacitate,viteza_medie){}
    
    
};


int main()
{
    int optiune;
    std::cin>>optiune;
    
    int nr_automobile;
    std::cin>>nr_automobile;
    
    std:: string tip;
    std::string nume;
    int capacitate;
    float viteza_medie;
    
    Automobil **auto_array = nullptr;
    auto_array = new Automobil*[nr_automobile];
    
    int k=0; //variab de lucru care pune pe pozitii
    
    //generare obiecte
    
    
    
       for(int i=0;i<nr_automobile;i++)
       {
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');   
           std::getline(std::cin,tip);
           std::getline(std::cin,nume);
           std::cin>>capacitate;
           std::cin>>viteza_medie;
           
           if(tip == "Masina")
           {
               *(auto_array+(k++))= new Masina(tip,nume,capacitate,viteza_medie);
           }
           if(tip == "Autocar")
           {
               *(auto_array+(k++))= new Autocar(tip,nume,capacitate,viteza_medie);
           }
       }

   if(optiune == 1)
   {
       for(int i=0;i<nr_automobile;i++)
       {
           (*(auto_array+i))->afisare_1();
       }
   }

   if(optiune == 2)
   {
   int x;
   std::cin>>x;
   
 
       for(int i=0;i<nr_automobile;i++)
       {
           if((*(auto_array+i))->get_tip() == "Masina")
           {
               (*(auto_array+i))->grup_persoane_2(x);
       
           }
           if((*(auto_array+i))->get_tip() == "Autocar")
           {
             (*(auto_array+i))->grup_persoane_2(x);  
           }
           
       }
   
   }
   
   if(optiune == 3)
   {
       int l; //lungimea drumului
       int t; //timp limita
       
       std::cin>>l;
       std::cin>>t;
       
       for(int i=0;i<nr_automobile;i++)
       {
            if((*(auto_array+i))->get_tip() == "Masina")
            {
                 (*(auto_array+i))->durata_drum_3(l,t);
            }
            if((*(auto_array+i))->get_tip() == "Autocar")
            {
                 (*(auto_array+i))->durata_drum_3(l,t);
            }
       }
   }
    
    if(optiune == 4)
    {
        float v[nr_automobile][2];
        int x;
        std::cin>>x;
        
        
        for(int i=0;i<nr_automobile;i++)
        {
            v[i][0]=(*(auto_array+i))->poluare_4(x);
            v[i][1]=(float )i;
        }
        
        //std::sort(valori,valori+nr_automobile);
        
       /* 
        for(int i=0;i<nr_automobile;i++)
        {
          
            for( int j=0;j<nr_automobile;j++)
            {
                if(valori[i] == (*(auto_array+j))->poluare_4(x))
                {
                    std::cout<<(*(auto_array+j))->get_nume()<<std::endl;
                    //std::cout<<(*(auto_array+j))->poluare_4(x)<<std::endl;
                }
            }
        }
        */
        
        for(int i=1;i<nr_automobile;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j][0]>v[i][0])
                {
                    int copie;
                    copie=v[j][0];
                    v[j][0]=v[i][0];
                    v[i][0]=copie;
                    copie=v[j][1];
                    v[j][1]=v[i][1];
                    v[i][1]=copie;
                }
            }
        }
        
        for(int i=0;i<nr_automobile;i++)
        {
             std::cout<<(*(auto_array+(int)(v[i][1])))->get_nume()<<std::endl;
        }
        
        
    }
    
    
    return 0;
}