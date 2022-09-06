#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>


class Angajat{
    
  protected:
     std::string nume;
     std::string functie;
     float salariu_baza;
     float procent_taxe_salariu;
     
  public:
     Angajat(){}
     Angajat(std::string nume,float salariu_baza,std::string functie,float procent_taxe_salariu):nume(nume),salariu_baza(salariu_baza),functie(functie),procent_taxe_salariu(procent_taxe_salariu){}
     
     //getters
     virtual float get_salariu_net(float x)
     {
         return 0;
     }
     virtual float get_salariu_brut()
     {
         return 0;
     }
     virtual std::string get_nume()
     {
         return this->nume;
     }
     virtual std::string get_functie()
     {
         return this->functie;
     }
    virtual void set_functie(std::string functie_noua)
    {
        this->functie = functie_noua;
        
    }

    //functii
    
    virtual void afisare_1(){}
    virtual void calcul_salarii_2(){}
    virtual void marire_salariu_3(float x){}
    
    //Destructor
        virtual ~Angajat(){std::cout<<"Destructor Angajat"<<std::endl;}
    
};

class Analist:public Angajat {
    
  protected:
  
  
  public:
     Analist(){}
     Analist(std::string nume,float salariu_baza,std::string functie,float procent_taxe_salariu):Angajat(nume,salariu_baza,functie,procent_taxe_salariu){}
     
     void afisare_1()
     {
         std::cout<<nume<<"\n"<<functie<<std::endl;
     }
     
    void calcul_salarii_2()
    {
        int salariu_brut;
        int salariu_net;
        
        salariu_brut=salariu_baza;
        salariu_net=(salariu_baza*(100-40))/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu brut: "<<salariu_brut<<std::endl;
        std::cout<<"Salariu Net: "<<salariu_net<<std::endl;
        
    }
    
    void maririe_salariu_3(float x)
    {
        int salariu_vechi;
        int salariu_nou;
        
        salariu_vechi=salariu_baza;
        salariu_nou=salariu_baza+salariu_baza*x/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu de baza vechi: "<<salariu_vechi<<std::endl;
        std::cout<<"Salariu de baza nou: "<<salariu_nou<<std::endl;
        
    }
    //Destructor
        ~Analist(){std::cout<<"Destructor Analist"<<std::endl;}
    
};

class Programator:public Analist{
    
  protected:
     float procent_deducere_salariu_it;
     
  public:
     Programator(){}
     Programator(std::string nume,float salariu_baza,std::string functie,float procent_taxe_salariu,float procent_deducere_salariu_it):Analist(nume,salariu_baza,functie,procent_taxe_salariu),procent_deducere_salariu_it(procent_deducere_salariu_it){}
     
     void afisare_1()
     {
         std::cout<<nume<<"\n"<<functie<<std::endl;
     }
    
    void calcul_salarii_2()
    {
        int salariu_brut;
        int salariu_net;
        
        salariu_brut=salariu_baza;
        salariu_net=(salariu_baza*(100-40+10))/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu brut: "<<salariu_brut<<std::endl;
        std::cout<<"Salariu Net: "<<salariu_net<<std::endl;
    }
    
    void marire_salariu_3(float x)
    {
        int salariu_vechi;
        int salariu_nou;
        
        salariu_vechi=salariu_baza;
        salariu_nou=salariu_baza+salariu_baza*x/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu de baza vechi: "<< salariu_vechi<<std::endl;
        std::cout<<"Salariu de baza nou: "<< salariu_nou<<std::endl;
    }
    
     ~Programator(){std::cout<<"Destructor Programator"<<std::endl;}
};

class LiderEchipaProgramare:public Programator{
    
  protected: 
     float bonus_vechime_functie;
     int vechime_functie;
     
  public:
    LiderEchipaProgramare(){}
    LiderEchipaProgramare(std::string nume, float salariu_baza, std::string functie, float procent_taxe_salariu, float procent_deducere_salariu_it, float bonus_vechime_functie, int vechime_functie): Programator(nume, salariu_baza, functie, procent_taxe_salariu, procent_deducere_salariu_it), bonus_vechime_functie(bonus_vechime_functie), vechime_functie(vechime_functie){}
    
    void afisare1()
    {
        std::cout<<nume<<"\n"<<functie<<std::endl;
    }
    
    void calcul_salarii_2()
    {
        int salariu_brut;
        int salariu_net;
        
        salariu_brut=salariu_baza+ 500 * vechime_functie;
        salariu_net=((salariu_baza+ 500 * vechime_functie)*(100-40+10))/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu brut: "<<salariu_brut<<std::endl;
        std::cout<<"Salariu Net: "<<salariu_net<<std::endl;
    }
    
    void marire_salariu_3(float x)
    {
            
        int salariu_vechi;
        int salariu_nou;
            
        salariu_vechi=salariu_baza;
        salariu_nou=salariu_baza+salariu_baza*x/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu de baza vechi: "<< salariu_vechi<<std::endl;
        std::cout<<"Salariu de baza nou: "<< salariu_nou<<std::endl;
            
    }
     //Destructor
        ~LiderEchipaProgramare(){std::cout<<"Destructor LiderEchipaProgramare"<<std::endl;}
    
};

int main()
{
    int nr_angajati;
    std::string nume;
    std::string functie;
    int salariu_baza;
    
    std::cin>>nr_angajati;
    
    //array
    Angajat **angajat_array = nullptr;
    angajat_array = new Angajat*[nr_angajati];
    
    int k=0;
    //generare fiecare obiect
    for(int i=0;i<nr_angajati;i++)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin, nume);
        std::cin>>functie;
        std::cin>>salariu_baza;
        
        if(functie == "Analist")
        {
            *(angajat_array+(k++))=new Analist(nume,salariu_baza,functie,0);
        }
        if(functie == "Programator")
        {
            *(angajat_array+(k++))=new Programator(nume,salariu_baza,functie,0,0);
        }
        if(functie == "LiderEchipaProgramare")
        {
            int vechime_functie;
            std::cin>>vechime_functie;
            
            *(angajat_array+(k++))=new LiderEchipaProgramare(nume,salariu_baza,functie,0,0,0,vechime_functie);
            
        }
    }
    int optiune;
    std::cin>>optiune;
    
    if(optiune==1)
    {
        for(int i=0;i<nr_angajati;i++)
        {
            (*(angajat_array+i))->afisare_1();
        }
    }
    
    if(optiune == 2)
    {
         for(int i=0;i<nr_angajati;i++)          
         {
             (*(angajat_array+i))->calcul_salarii_2();
         }
    }
    
    if(optiune==3)
    {
        std::string functie_analist;
        std::string functie_programator;
        std::string functie_lider;
        
        int procent_analist;
        int procent_programator;
        int procent_lider;
        
        std::cin>>functie_analist; //citire pe acelasi rand functie_in_firma procent_marire_salariu
        std::cin>>procent_analist;
        
        std::cin>>functie_programator;
        std::cin>>procent_programator;
        
        std::cin>>functie_lider;
        std::cin>>procent_lider;
        
        for(int i=0;i<nr_angajati;i++)
        {
            if((*(angajat_array+i))->get_functie() == functie_analist)
            {
                (*(angajat_array+i))->marire_salariu_3(procent_analist);
            }
            if((*(angajat_array+i))->get_functie() == functie_programator)
            {
                (*(angajat_array+i))->marire_salariu_3(procent_programator);
            }
            if((*(angajat_array+i))->get_functie() == functie_lider)
            {
                (*(angajat_array+i))->marire_salariu_3(procent_lider);
            }
            
        }
        
    }
    
    if(optiune == 4){
        
        std::string nume_4;
        std::string functie_4;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin, nume_4);
        std::cin>>functie_4;
        
        //Cautam persoana promovata
        int contor;
        for(int i=0; i<nr_angajati; i++){
            if((*(angajat_array+i))->get_nume() == nume_4)
                contor=i;
        }
        
        
        //Setam noua functie si apelam DESTRUCTOR
        delete (*(angajat_array+contor));
        
        //Facem obiect nou de noua Functie Promovata in locul celui sters
        if(functie_4 == "Analist"){
            //Punem elementele in obiect
            *(angajat_array+(contor)) = new Analist(nume_4, 0, functie_4, 0);
        }
        
        if(functie_4 == "Programator"){
            //Punem elementele in obiect
            *(angajat_array+(contor)) = new Programator(nume_4, 0, functie_4, 0, 0);
        }
        
        if(functie_4 == "LiderEchipaProgramare"){
            
            //Punem elementele in obiect
            *(angajat_array+(contor)) = new LiderEchipaProgramare(nume_4, 0, functie_4, 0, 0, 0, 0);
        }

    
        
        //Afisam angajatii
        for(int i=0; i<nr_angajati; i++){
            (*(angajat_array+i))->afisare_1();
        }    
        
        
        
    }
    
    return 0;
}