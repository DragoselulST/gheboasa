#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <iomanip>


class Angajat{
    protected:
        std::string tip_angajat; //rol de identificator de obiecte din array
        std::string nume;
        std::string departament;
    public:
    
        Angajat(){}
        Angajat(std::string tip_angajat, std::string nume, std::string departament):tip_angajat(tip_angajat),nume(nume),departament(departament){}
    
        
        //getters
        std::string get_tip_angajat()
        {
            return this->tip_angajat;
        }
        
        std::string get_nume()
        {
            return this->nume;
        }
        std::string get_departament()
        {
            return this->departament;
        } 
        
        //cerinta 1
        virtual void afisare(){}; 
        //pt 2
        virtual float salariu_brut(){ return 0 ; }
        virtual float salariu_brut_IT(){ return 0 ; }
        //Functii cerinta 3 DOAR PENTRU SALARIATI
        virtual float rentabilitate_angajat(){ return 0; }
        virtual int concediu(){ return 0; }
        
};

class Salariat : public Angajat{
    
   private:
       int norma;
       int vechime;
       float salariu_net;
       
    public:
       Salariat(){}
       Salariat(std::string tip_angajat, std::string nume, std::string departament, int norma, int vechime, float salariu_net):Angajat(tip_angajat, nume, departament),norma(norma),vechime(vechime),salariu_net(salariu_net){}
       
       void afisare()
       {
           std::cout<<nume<<" "<<norma<<" "<<vechime<<" "<<salariu_net<<std::endl;
       }

       float salariu_brut()
       {
           float salariu_brut=0;
           salariu_brut=salariu_net*12/0.55;
           return salariu_brut;
       }
       
       float salariu_brut_IT()
       {
           float salariu_brut_IT=0;
           salariu_brut_IT=salariu_net*12/0.65;
           return salariu_brut_IT;
       }
       int concediu()
       {
           int concediu;
           concediu=vechime/3;
           return concediu;
       }
       float rentabilitate_angajat()
       {
           float rentabilitate_angajat=0;
           
           if(departament == "IT")
           {
               rentabilitate_angajat=norma*(250-concediu())/salariu_brut_IT();
           }
           if(departament != "IT")
           {
               rentabilitate_angajat=norma*(250-concediu())/salariu_brut();
           }
           return rentabilitate_angajat;
       }
};

class Colaborator : public Angajat{
    
  private:
     float onorariu;
     float nr_prestari_anuale;
     
  public:
     Colaborator(){}
     Colaborator(std::string tip_angajat, std::string nume, std::string departament, float onorariu, float nr_prestari_anuale):Angajat(tip_angajat, nume, departament),onorariu(onorariu),nr_prestari_anuale(nr_prestari_anuale){}
     
     void afisare()
     {
        std::cout<<nume<<" "<<onorariu<<" "<<nr_prestari_anuale<<std::endl;
     }
    
    float salariu_brut()
    {
        float salariu_brut=0;
        salariu_brut=onorariu*nr_prestari_anuale/0.55;
        return salariu_brut;
    }
    
    float salariu_brut_IT()
    {
        float salariu_brut_IT=0;
        salariu_brut_IT=onorariu*nr_prestari_anuale/0.65;
        return salariu_brut_IT;
    }
    
};


int main()
{
    
    int nr_angajati;
    std::string tip_angajat;
    std::string nume_angajat;
    std::string nume_departament;
    
    
    
    std::cin>>nr_angajati;
    //Facem Array de Obiecte (Toate pot sa fie de o clasa diferita)
        //Folosim Alocare Dinamica
        
    Angajat **angajat_array = nullptr;
    angajat_array = new Angajat*[nr_angajati];
    
    int k=0; //var de lucru care pune pe pozitii
    
    //generaam fiecare obiect
    for(int i=0;i<nr_angajati;i++)
    {
        std::cin>>tip_angajat;
        std::cin>>nume_angajat;
        std::cin>>nume_departament;
        
        //Salariat
        if(tip_angajat == "salariat")
        {
            int norma_zilnica;
            int vechime_angajat;
            float salariu_lunar;
            
            std::cin>>norma_zilnica; 
            std::cin>>vechime_angajat;
            std::cin>>salariu_lunar;
            
            //punem elem in obiect
            *(angajat_array+(k++))=new Salariat(tip_angajat,nume_angajat,nume_departament,norma_zilnica, vechime_angajat, salariu_lunar);
        }
        
        if(tip_angajat == "colaborator")
        {
            int onorariu_net;
            int prestari_anuale;
            
            std::cin>>onorariu_net;
            std::cin>>prestari_anuale;
            
            *(angajat_array+(k++))=new Colaborator(tip_angajat,nume_angajat,nume_departament,onorariu_net, prestari_anuale);
        }
        
    }
    
    int optiune;
    std::cin>>optiune;
    
    if(optiune==1)
    {
        std::string departament_1;
        std::cin>>departament_1;
        
        for(int i=0;i<nr_angajati;i++)
        {
            if(departament_1== (*(angajat_array+i))->get_departament())
                (*(angajat_array+i))->afisare();
        }
    }
    
    if(optiune==2)
    {
        int salariu_brut_2;
        
        std::string nume_angajat_2;
        std::cin>>nume_angajat_2;
        
        for(int i=0;i<nr_angajati;i++)
        {
             //Conteaza daca Angajatul este Salariat sau Colaborator pentru ca difera modul de calcul
            //Fiecare tip are functie definita pentru asa ceva
            if(nume_angajat_2 == (*(angajat_array+i))->get_nume())
            {
                 //Daca Salariatul sau Colaboratorul este in departamentul IT
                 if((*(angajat_array+i))->get_departament() == "IT")
                 {
                     salariu_brut_2= (*(angajat_array+i))->salariu_brut_IT();
                     std::cout<<salariu_brut_2<<std::setprecision(2)<<std::endl;
                 }
                 
                 //Daca Salariatul sau Colaboratorul NU este in departamentul IT
                 if((*(angajat_array+i))->get_departament() != "IT")
                 {
                     salariu_brut_2= (*(angajat_array+i))->salariu_brut();
                     std::cout<<salariu_brut_2<<std::setprecision(2)<<std::endl;
                 }
            }
        }
    }
    
    if(optiune ==3)
    {
        int pozitie=0;    //Pozitia in Array unde O SA SE AFLE persoana care are maxim
        float rentabilitate_maxima=0;
        float rentabilitate_contor=0;
        
        //Cautam primul salariat si salvam rentabilitatea sa o folosim pe post de CONTOR
        for(int i=0;i<nr_angajati;i++)
        {
            if((*(angajat_array+i))->get_tip_angajat() == "salariat")
            {
                rentabilitate_maxima=(*(angajat_array+i))->rentabilitate_angajat();
            }
        }
        //cautam rentabilitate maxima
        for(int i=0;i<nr_angajati;i++)
        {
            if((*(angajat_array+i))->get_tip_angajat() == "salariat")
            {
                rentabilitate_contor=(*(angajat_array+i))->rentabilitate_angajat();
                if(rentabilitate_maxima < rentabilitate_contor)
                  rentabilitate_maxima = rentabilitate_contor;
                  pozitie=i;
                
            }
        }
        std::cout<<(*(angajat_array+pozitie))->get_nume()<<std::endl;
    }
    
    if(optiune ==4)
    {
        int salariu_mediu=0;
        
        std::string departament_4;
        std::cin>>departament_4;
        
        for(int i=0;i<nr_angajati;i++)
        {
            if((*(angajat_array+i))->get_departament()==departament_4)
            {
                salariu_mediu=salariu_mediu+ (*(angajat_array+i))->salariu_brut();
            }
        }
        
        //La final se imparte la 2 pentru ca asa e in prb
        
        std::cout<<salariu_mediu/2<<std::setprecision(2)<<std::endl;
    }
    
    return 0;
}