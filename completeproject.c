                                                          // Sem Project code
                                                          
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    char Symbol[3];
    int Atomic_Number;
    float Atomic_Mass;
    int Group;
    int Period;
    char State[10];
    int Valency;
    char Boiling_point[10];
    char Melting_point[10];
    char Atomic_Radius[10];
    char Electron_Config[20];
    struct node *next;
};

struct node *start;
struct node *current;
struct node *iterator;
struct node *iterator2;
struct node *adder;
struct node *remover;

// function for displaying data by Atomic number

void display_by_An(int data)
{
	
    iterator = start;
    while (iterator->Atomic_Number != data )
    {
    	if(iterator->next==NULL){
        	printf("Not Available Deleted or Not Exist");
        return 0;
		}
        iterator = iterator->next;
        
    }
    printf("Name of element Is :%s\n \n", iterator->name);
    printf(" Symbol of element :%s\n \n", iterator->Symbol);
    printf("Atomic Number of element :%d\n \n", iterator->Atomic_Number);
    printf("Atomic Mass of Element :%f\n \n", iterator->Atomic_Mass);
    printf("Present in Group :%d\n \n", iterator->Group);
    printf("Present in Period :%d\n \n", iterator->Period);
    printf("Physical state :%s\n \n", iterator->State);
    printf("Valency Of Element :%d\n \n", iterator->Valency);
    printf("Boiling Point :%s\n \n", iterator->Boiling_point);
    printf("Melting Point :%s\n \n", iterator->Melting_point);
    printf("Atomic Radius :%s\n \n", iterator->Atomic_Radius);
    printf("Electronic Configuration  :%s\n \n", iterator->Electron_Config);
        iterator = start;
}


// function for displaying data by Element name
void display_by_name(char By_name[])
{

  iterator=start;

while(iterator!=NULL){
   if( iterator->name[0] == By_name[0] && iterator->name[1] == By_name[1] && iterator->name[2] == By_name[2]  && iterator->name[3] == By_name[3] ){
    printf("\n");
    printf("Name of element Is : %s\n \n", iterator->name);
    printf("Symbol of element :%s\n \n", iterator->Symbol);
    printf("Atomic Number of element :%d\n \n", iterator->Atomic_Number);
    printf("Atomic Mass of Element :%f\n \n", iterator->Atomic_Mass);
    printf("Present in Group :%d\n \n", iterator->Group);
    printf("Present in Period :%d\n \n", iterator->Period);
    printf("Physical state :%s\n \n", iterator->State);
    printf("Valency Of Element :%d\n \n", iterator->Valency);
    printf("Boiling Point :%s\n \n", iterator->Boiling_point);
    printf("Melting Point :%s\n \n", iterator->Melting_point);
    printf("Atomic Radius :%s\n \n", iterator->Atomic_Radius);
    printf("Electronic Configuration  :%s\n \n", iterator->Electron_Config);
    // iterator=start;
    break;
   }
   else{
    
    iterator = iterator->next;
   }
}
    
}


// function for displaying all 118 element data

void displayall()
{
    iterator2 = start;

    do
    {
        printf("\n");
        printf("Name of element Is : %s\n", iterator2->name);
        printf("Symbol of element :%s\n", iterator2->Symbol);
        printf("Atomic Number of element :%d\n", iterator2->Atomic_Number);
        printf("Atomic Mass of Element :%f\n", iterator2->Atomic_Mass);
        printf("Present in Group :%d\n", iterator2->Group);
        printf("Present in Period :%d\n", iterator2->Period);
        printf("Physical state :%s\n", iterator2->State);
        printf("Valency Of Element :%d\n", iterator2->Valency);
        printf("Boiling Point :%s\n", iterator2->Boiling_point);
        printf("Melting Point :%s\n", iterator2->Melting_point);
        printf("Atomic Radius :%s\n", iterator2->Atomic_Radius);
        printf("Electronic Configuration  :%s\n", iterator2->Electron_Config);
        printf("---------------------------------------------------------------\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        iterator2 = iterator2->next;
    } while (iterator2 != NULL);
}

// function for Creating periodic table 

void insert(char name[], char sym[], int AN, float AM, int G, int P, char st[], int val, char bp[], char mp[], char ar[], char ec[])
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    strcpy(temp->Symbol, sym);
    temp->Atomic_Number = AN;
    temp->Atomic_Mass = AM;
    temp->Group = G;
    temp->Period = P;
    strcpy(temp->State, st);
    temp->Valency = val;
    strcpy(temp->Boiling_point, bp);
    strcpy(temp->Melting_point, mp);
    strcpy(temp->Atomic_Radius, ar);
    strcpy(temp->Electron_Config, ec);

    current = start;

    if (current == NULL)
    {
        start = temp;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }

    temp->next = NULL;
}

void compare(char check[])
{
    int i, n = -1;
    
     char save[n];
    for (i = 0; i < 20; i++)
    {

        if (check[i] >= 'a' && check[i] <= 'z')
        {
            n = n + 1;
            save[i] = check[i];
      
        }
        else
        {
            break;
        }
    }
 
    display_by_name(save);


}

void new_insert( char name[], char sym[], int AN, float AM, int G, int P, char st[], int val, char bp[], char mp[], char ar[], char ec[])
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    adder=start;
    strcpy(temp->name, name);
   
    strcpy(temp->Symbol, sym);
  
    temp->Atomic_Number = AN;
   
    temp->Atomic_Mass = AM;
  
    temp->Group = G;
  
    temp->Period = P;
  
    strcpy(temp->State, st);
    
    temp->Valency = val;
   
    strcpy(temp->Boiling_point, bp);
 
    strcpy(temp->Melting_point, mp);
   
    strcpy(temp->Atomic_Radius, ar);

    strcpy(temp->Electron_Config, ec);
   
	

	
	
	while(adder->next !=NULL){
		adder=adder->next;
	}
	adder->next= temp;
	temp->next=NULL;
		printf("\n Element added succesfully");

	
}

void delete(int number){
	struct node *ptr;
	remover=start;
	ptr=start;
	
	while(remover->Atomic_Number-1!=number-1){
		ptr=ptr->next;
		remover=ptr->next;
	}
	ptr->next=remover->next;
	free(remover);
	printf("%d : Deleted succesfully",number);
}
// main function

void main()
{
    int mainchoice, Search_by_A_Number;
    int SubChoice;
    char Search_by_A_Name[20];
     int AN;
    int number;
    // inserting data in structure by using function call

    insert("hydrogen", "h", 1, 1.008, 1, 1, "Gas", 1, "20.28k", "13.81", "120nm", "1s1");

    insert("helium", "he", 2, 4.0026, 18, 1, "Gas", 0, "4.22k", "0.95k", "140nm", "1s2");

    insert("lithium", "li", 3, 7, 1, 2, "solid", 1, "1615k", "453.65k", "182nm", "[he]2s1");

    insert("beryllium", "be", 4, 9.01, 2, 2, "solid", 2, "2744k", "1560k", "153pm", "[he]2s2");

    insert("boron", "b", 5, 10.81, 13, 2, "solid", 3, "4273k ", "2348", "192 pm", "[he]2s2 2p1");

    insert("carbon", "c", 6, 12.01, 14, 2, "Solid", 4, "4098k", "3823k", "170pm", "[he]2s2 2p2");

    insert("nitrogen", "n", 7, 14.0, 15, 2, "Gas", -1, "77.36k", "63.15", "155pm", "[he]2s2 2p3");

    insert("oxygen", "o", 8, 15.99, 16, 2, "Gas", -2, "90.2k", "54.36", "152nm", "[he]2s2 2p4");

    insert("fluorine", "f", 9, 18.99, 17, 2, "Gas", -1, "85.05k", "53.03", "135pm", "[he]2s2 2p5");

    insert("neon", "ne", 10, 20.18, 18, 2, "Gas", 0, "27.07k", "24.56", "154pm", "[he]2s2 2p6");

    insert("sodium", "na", 11, 22.98, 1, 3, "solid", 1, "1656k", "370.95k", "227pm", "[ne]3s1");

    insert("magnesium", "mg", 12, 24.305, 2, 3, "solid", 2, "1363k", "923k", "173pm", "[ne]3s2");

    insert(" aluminum", "al", 13, 26.98, 13, 3, "solid", 3, "2792k", "933.43k", "184pm", "[ne]3s2 3p 1");

    insert(" silicon", "si", 14, 28.00, 14, 3, "solid", +-4, "3538k", "1687k", "210pm", "[ne]3s2 3p2");

    insert("phosphorus", "p", 15, 30.90, 15, 3, "solid", 3, "553.65k", "317.3k", "180pm", "[ne]3s2 3p3");

    insert("sulfur", "s", 16, 32.07, 16, 3, "solid", 2, "717.75k", "388k", "180pm", "[ne]3s2  3p4");

    insert("chlorine", "cl", 17, 35.45, 17, 3, "gas", 1, "239.11k", "171.65k", "175pm", "[ne]3s2 3p5");

    insert("argon", "ar", 18, 39.9, 18, 3, "gas", 0, "87.3k", "83.8k", "188pm", "[ne]3s2 3p6");

    insert("potassium", "k", 19, 39, 1, 4, "solid", 1, "1032k", "336.53", "275pm", "[ar]4s1");

    insert("calcium", "ca", 20, 40.28, 2, 4, "solid", 2, "1756k", "1115k", "231pm", "[ar]4s2");

    insert("scandium", "sc", 21, 44.95, 3, 4, "solid", 3, "3109k", "1814k", "211pm", "[ar]4s2 3d1");

    insert("titanium", "ti", 22, 47.86, 4, 4, "solid", 4, "3560k", "1941k", "187pm", "[ar]4s2 3d2");

    insert("vanadium", "v", 23, 50.94, 5, 4, "solid", 3, "3680k", "2183k", "179pm", "[ar]4s2 3d3");

    insert("cromium", "cr", 24, 51.99, 6, 4, "solid", 2, "2944k", "2180k", "189pm", "[ar]3d5 4s1");

    insert("maganese", "mn", 25, 54.93, 7, 4, "solid", 4, "2334k", "1519k", "197pm", "[ar]4s2 3d5");

    insert("iron", "fe", 26, 55.84, 8, 4, "solid", 3, "3134k", "1811k", "194pm", "[ar]4s2 3d6");

    insert("cobalt", "co", 27, 58.93, 9, 4, "solid", 2, "3200k", "1768k", "192pm", "[ar]4s2 3d7");

    insert("nikel", "ni", 28, 58.69, 10, 4, "solid", 3, "3186k", "1728k", "163pm", "[ar]4s2 3d8");

    insert("copper", "cu", 29, 63.55, 11, 4, "solid", 2, "2835k", "1357k", "140pm", "[ar]4s1 3d10");

    insert("zinc", "zn", 30, 65.4, 12, 4, "solid", 2, "1180k", "692.68k", "139pm", "[ar]4s2 3d10");

    insert("gallium", "ga", 31, 69.723, 13, 4, "solid", 3, "2477k", "302.91k", "187pm", "[ar]4s2 3d10 ap1");

    insert("germanium", "ge", 32, 72.63, 14, 4, "solid", 4, "3106k", "1211k", "211pm", "[ar]4s2 3d10 4p2");

    insert("arsenic", "as", 33, 74.92, 15, 4, "solid", 3, "887k", "1090k", "185pm", "[ar]4s2 3d10 4p3");

    insert("selemium", "se", 34, 78.97, 16, 4, "solid", 4, "958k", "493k", "190pm", "[ar]4s2 3d10 4p4");

    insert("bromine", "br", 35, 79.920, 17, 4, "solid", 1, "331k", "265.95k", "183pm", "[ar]4s2 3d10 4p5");

    insert("krypton", "kr", 36, 83.90, 18, 4, "solid", 0, "119.93k", "115.79k", "202pm", "[ar]4s2 3d10 4p6");

    insert("rubidium", "rb", 37, 85.468, 1, 5, "solid", 1, "961k", "312.46k", "303pm", "[kr]5s1");

    insert("strontium", "sr", 38, 87.98, 2, 5, "solid", 2, "1655k", "1050k", "249pm", "[kr]5s2");

    insert("yttrium", "y", 39, 88.90, 3, 5, "solid", 3, "3618k", "1795k", "219pm", "[kr]5s2 4d1");

    insert("zirconium  ", "zr", 40, 91.22, 4, 5, "solid", 4, "4682k", "2128k", "186pm", "[kr]5s24d2");
    
     
    insert("zirconium  " , "Zr", 40,91.22 , 4, 5, "solid", 4, "4650k", "2128.15k", "186pm", "[kr]5s2 4d2");
insert("niobium" , "Nb", 41,92.906 , 5, 5, "solid", 5, "5017.15k", "2750.15k", "198pm", "[kr]5s1 4d4");
insert("molybdenum" , "Mo", 42,95.94 ,6,5, "solid", 6, "4912.15k", "2896.15k", "190pm", "[kr]5s1 4d5");
insert("technetium" , "Tc", 43,98, 7, 5, "solid", 7, "4538.15k", "2430.15k", "183pm", "[kr]5s2 4d5");
insert("ruthenium" , "Ru", 44,101.07, 8, 5, "solid", 6, "4423.15k", "2607.15k", "178pm", "[kr]5s1 4d7");
insert("rhodium" , "Rh", 45,102.905, 9, 5, "solid", 6, "3968.15k", "2237.15k", "173pm", "[kr]5s1 4d8");
insert("palladium" , "Pd", 46,106.42 , 10, 5, "solid", 4, "3236.15k", "1828.05k", "169pm", "[kr]4d10");
insert("silver" , "Ag", 47,107.868, 11, 5, "solid", 2, "2435.15k", "1234.93k", "165pm", "[kr]5s1 4d10");
insert("cadmium" , "Cd", 48,112.411, 12, 5, "solid", 2, "1040.15k", "594.22k", "161pm", "[kr]5s2 4d10");
insert("indium" , "In", 49,114.818, 13, 5, "solid", 3, "2345.15k", "429.75k", "156pm", "[kr]5s2 4d10 5p1");
insert("tin" , "Tn", 50,118.71, 14, 5, "solid", 4, "2875.15k", "505.08k", "145pm", "[kr]5s2 4d10 5p2");
insert("antimony" , "Sb", 51,121.76, 15, 5, "solid", 5, "1908.15k", "903.78k", "133pm", "[kr]5s2 4d10 5p3");
insert("tellurium" , "Te", 52,127.6, 16, 5, "solid", 6, "1261.15k", "722.66k", "123pm", "[kr]5s2 4d10 5p4");
insert("iodine" , "I", 53,126.904, 17, 5, "solid", 7, "457.45k", "386.85k", "115pm", "[kr]5s2 4d10 5p5");
insert("xenon" , "Xe", 54,131.293, 18, 5, "gas", 6, "165.05k", "161.40k", "108pm", "[kr]5s2 4d10 5p6");
insert("cesium" , "Cs", 55,132.905, 1, 6, "solid", 1, "944.15k", "301.65k", "298pm", "[Xe]6s1");
insert("barium" , "Ba", 56,137.327, 2, 6, "solid", 2, "3118.15k", "1000.15k", "253pm", "[Xe]6s2");
insert("lanthanum" , "La", 57,138.905, 3, 6, "solid", 3, "3737.15k", "1193.15k", "pm", "[Xe]6s2 5d1");
insert("cerium" , "Ce", 58,140.116, 3, 6, "solid", 4, "3716.15k", "1068.15k", "pm", "[Xe]6s2 5d1 4f1");
insert("praseodymium" , "Pr", 59,140.907, 3, 6, "solid", 4, "3403.15k", "1208.15k", "247pm", "[Xe]6s2 4f3");
insert("neodymium" , "Nd", 60,144.24, 3, 6, "solid", 3, "3347.15k", "1297.15k", "206pm", "[Xe]6s2 4f4");
insert("promethium" , "Pm", 61,145, 3, 6, "solid", 3, "3273.15k", "1315.15k", "205pm", "[Xe]6s2 4f5");
insert("samarium" , "Sm", 62,150.36, 3, 6, "solid", 3, "2173.15k", "1345.15k", "238pm", "[Xe]6s2 4f6");
insert("europium" , "Eu", 63,151.964, 3, 6, "solid", 3, "1802.15k", "1099.15k", "231pm", "[Xe]6s2 4f7");
insert("gadolinium" , "Gd", 64,157.25, 3, 6, "solid", 3, "3273.15k", "1585.15k", "233pm", "[Xe]6s2 5d1 4f7");
insert("terbium" , "Tb", 65,158.92, 3, 6, "solid", 3, "3396.15k", "1629.15k", "225pm", "[Xe]6s2 4f9");
insert("dysprosium" , "Dy", 66,162.5, 3, 6, "solid", 3, "2835.15k", "1680.15k", "228pm", "[Xe]6s2 4f10");
insert("holmium" , "Ho", 67,164.93, 3, 6, "solid", 3, "2873.15k", "1734.15k", "226pm", "[Xe]6s2 4f11");
insert("erbium" , "Er", 68,167.259, 3, 6, "solid", 3, "3141.15k", "1802.15k", "226pm", "[Xe]6s2 4f12");
insert("thulium" , "Tm", 69,168.934, 3, 6, "solid", 3, "2223.15k", "1818.15k", "222pm", "[Xe]6s2 4f13");
insert("ytterbium" , "Yb", 70,173.04, 3, 6, "solid", 3, "1469.15k", "1097.15k", "222pm", "[Xe]6s2 4f14");
insert("lutetium" , "Lu", 71,174.967, 3, 6, "solid", 3, "3675.15k", "1925.15k", "217pm", "[Xe]6s2 5d1 4f14");
insert("hafnium" , "Hf", 72,178.49, 4, 6, "solid", 4, "4876.15k", "2506.15k", "208pm", "[Xe]6s2 5d2 4f14");
insert("tantalum" , "Ta", 73,180.9479, 5, 6, "solid", 5, "5731.15k", "3290.15k", "200pm", "[Xe]6s2 5d3 4f14");
insert("tungsten" , "W", 74,183.84, 6, 6, "solid", 6, "6203.15k", "3695.15k", "193pm", "[Xe]6s2 5d4 4f14");
insert("rhenium" , "Re", 75,186.207, 7, 6, "solid", 7, "5903.15k", "3459.15k", "188pm", "[Xe]6s2 5d5 4f14");
insert("osmium" , "Os", 76,190.23, 8, 6, "solid", 6, "5285.15k", "3306.15k", "185pm", "[Xe]6s2 5d6 4f15");
insert("iridium" , "Ir", 77,192.217, 9, 6, "solid", 6, "4403.15k", "2719.15k", "180pm", "[Xe]6s2 5d7 4f14");
insert("platinum" , "Pt", 78,195.078, 10, 6, "solid", 6, "4098.15k", "2041.15k", "177pm", "[Xe]6s2 5d9 4f14");
insert("gold" , "Au", 79,1196.967, 11, 6, "solid", 5, "3243.15k", "1337.15k", "174pm", "[Xe]6s1 5d10 4f14");
insert("mercury" , "Hg", 80,200.59, 12, 6, "liquid", 2, "629.88k", "234.32k", "171pm", "[Xe]6s2 5d10 4f14");
insert("thallium" , "Tl", 81,204.38, 13, 6, "solid", 3, "1746.15k", "577.15k", "156pm", "[Xe]6s2 6p1 5d10 4f14");
insert("lead" , "Pd", 82,207.2, 14, 6, "solid", 4, "2022.15k", "600.61k", "154pm", "[Xe]6s2 6p2 5d10 4f14");
insert("bismuth" , "Bi", 83,208.98, 15, 6, "solid", 5, "1837.15k", "544.65k", "143pm", "[Xe]6s2 6p3 5d10 4f14");
insert("polonium" , "Po", 84,209, 16, 6, "solid", 6, "1235.15k", "527.15k", "135pm", "[Xe]6s2 6p4 5d10 4f14");
insert("astatine" , "At", 85,210, 17, 6, "solid", 5, "610.15k", "575.15k", "127pm", "[Xe]6s2 6p5 5d10 4f14");
insert("radon" , "Rn", 86,222, 18, 6, "gas", 6, "211.45k", "202.15k", "120pm", "[Xe]6s2 6p6 5d10 4f14");
insert("francium" , "Fr", 87,223, 1, 7, "solid", 3, "303.15k", "953.15k", "null", "[Rn]7s1");
insert("radium" , "Ra", 88,226, 2, 7, "solid", 2, "2010.15k", "973.15k", "null", "[Rn]7s2");
insert("actinium" , "Ac", 89,227, 3, 7, "solid", 3, "3473.15k", "1500.15k", "null", "[Rn]7s2 6d1");
insert("thorium" , "Th", 90,232.038, 3, 7, "solid", 4, "5061.15k", "2023.15k", "null", "[Rn]7s2 6d2");
insert("protactinium" , "Pa", 91,231.036,3 , 7, "solid", 5, "4300.15k", "1841.15k", "null", "[Rn]7s2 5f2 6d1");
insert("uranium" , "U", 92,238.028, 3, 7, "solid", 6, "4404.15k", "1405.35k", "null", "[Rn]7s2 6d1 5f3");
insert("neptunium" , "Np", 93,237, 3, 7, "solid", 6, "4447.15k", "912.15k", "null", "[Rn]7s16d1 5f4");
insert("plutonium" , "Pu", 94,244, 3, 7, "solid", 6, "3501.15k", "912.55k", "null", "[Rn]7s2 5f6");
insert("americium" , "Am", 95,243, 3, 7, "solid", 4, "2880.15k", "1449.15k", "null", "[Rn]7s2 5f7");
insert("curium" , "Cm", 96,247, 3, 7, "solid", 4, "3383.15k", "1613.15k", "null", "[Rn]7s2 6d1 5f7");
insert("berkelium" , "Bk", 97,247, 3, 7, "solid", 4, "2900.15k", "1259.15k", "null", "[Rn]7s2 5f9");
insert("californium" , "Cf", 98,251, 3, 7, "solid", 4, "1743.15k", "1173.15k", "null", "[Rn]7s2 5f10");
insert("einstenium" , "Es", 99,252, 3, 7, "solid", 4, "1269.15k", "1133.15k", "null", "[Rn]7s2 5f11");
insert("fermium" , "Fm", 100,257, 3, 7, "solid", 3, "null", "1800.15k", "null", "[Rn]7s2 5f12");
insert("mendelevium" , "Md", 101,258, 3, 7, "solid", 3, "null", "1100.15k", "null", "[Rn]7s2 5f13");
insert("nobeliumm" , "No", 102,259, 3, 7, "solid", 3, "null", "1100.15k", "null", "[Rn]7s2 5f14");
insert("lawrencium" , "Lr", 103,262, 3, 7, "solid", 3, "null", "1900.15k", "null", "[Rn]7s2 7p1 5f12");
insert("rutherfordium" , "Rf", 104,261, 4, 7, "solid", 3, "5773.15k", "2373.15k", "null", "[Rn]7s2 6d2 5f14");
insert("dubnium" , "Db", 105,268, 5, 7, "solid", 5, "null", "null", "null", "[Rn]7s2 6d3 5f14");
insert("seaborgium" , "Sg", 106,271, 6, 7, "solid", 6, "null", "null", "null", "[Rn]7s2 6d4 5f14");
insert("bohrium" , "Bh", 107,270, 7, 7, "solid", 7, "null", "null", "null", "[Rn]7s2 6d5 5f15");
insert("hassium" , "Hs", 108,269, 8, 7, "solid", 0, "null", "null", "null", "[Rn]7s2 6d6 5f14");
insert("meitnerium" , "Mt", 109,278, 9, 7, "solid", 0, "null", "null", "null", "[Rn]7s2 6d7 5f14");
insert("darmstadtium" , "Ds", 110,281, 10, 7, "solid",0 , "null", "null","null", "[Rn]7s2 6d8 5f14");
insert("roentgenium" , "Rg", 111,281, 11, 7, "solid", 0, "null", "null", "null", "[Rn]7s2 6d9 5f14");
insert("copernicium" , "Cn", 112,285, 12, 7, "gas", 0, "357.15k", "null", "null", "[Rn]7s2 6d10 5f14");
insert("nihonium" , "Nh", 113,286, 13, 7, "solid", 0, "1403.15k", "703.15k", "null", "[Rn]7s2 7p1 6d10 5f14");
insert("flerovium" , "Fl", 114,289, 14, 7, "gas", 0, "213.15k", "null", "null", "[Rn]7s2 7p2 6d10 5f14");
insert("moscovium" , "Mc", 115,290, 15, 7, "solid", 0, "1373.15k", "673.15k", "null", "[Rn]7s2 7p3 6d10 5f14");
insert("livermorium" , "Lv", 116,293, 16, 7, "solid", 0, "1035.15k", "637.15k", "null", "[Rn]7s2 7p4 6d10 5f14");
insert("tennessine" , "Ts", 117,294, 17, 7, "solid", 0, "883.15k", "623.15k", "null", "[Rn]7s2 7p5 6d10 5f14");
insert("oganesson" , "Og", 118,294, 18, 7, "solid", 0, "353.15k", "null", "null", "[Rn]7s2 7p6 6d10 5f14");


    int temp;
    while (mainchoice != 5)
    {
        //        printf("    \n Main Menu \n  Enter your choice to Search  \n  1.Specific Element \n  2.All elements \n 3.Add new Element \n  .4.exit");
        //
        printf("                                                                  ____PERIODIC TABLE USING LINKEDLIST____\n");
        printf("\n");
        printf("...............................................................................Main Menu.....................................................................................\n");
        printf("\n");
        printf("                                                                        Enter your choice to search   \n");
        printf("                                                                            1.Specific Element        \n");
        printf("                                                                            2.All elements            \n");
         printf("                                                                            3.Add new Element                    \n");
           printf("                                                                            4.Delete Element                    \n");
     
        printf("                                                                            5.exit                    \n");
        scanf("%d", &mainchoice);

        switch (mainchoice)
        {

        case 1:
            printf("                                                                        Again Enter to find element  \n");
            printf("                                                                            1. By name        \n");
            printf("                                                                            2. By Atomic Number            \n");
            //            printf("\n Again Enter to find element \n 1. By name \n 2. by Atomic Number \n ");
            scanf("%d", &SubChoice);
            if (SubChoice == 1)
            {
                printf("enter name of element in lowercase :\t");
                scanf("%s", Search_by_A_Name);
    
                compare(Search_by_A_Name);
                
            }
            else if (SubChoice == 2)
            {
                printf("                                                                       Enter Atomic number of element : \t");
                //                printf("enter Atomic number of element\n");
                scanf("%d", &Search_by_A_Number);
                printf("\n \n \n ");
                display_by_An(Search_by_A_Number);
            }
            else
            {
                printf("Enter right choice");
            }
            break;

        case 2:
            displayall();
            break;
            
             case 3:
	printf("Enter Atomic Number : ");
	scanf("%d",&AN);
	
	if(AN>0 && AN<=118){
		printf("Element is Present add another element");
	}
	else{
		char ec[20];
	printf("Enter electronic configuration :");
	scanf("%s",&ec);
		char ar[10];
	printf("Enter Atomic radius of element :");
	scanf("%s",&ar);
		float val;
		printf("Enter Valency of element:");
	scanf("%d",&val);
		
			char st[10];
	printf("Enter state of element:");
	scanf("%s",&st);
	
		char bp[15];
	printf("Enter boiling point of :");
	scanf("%s",&bp);
	
		char mp[15];
	printf("Enter melting point of: ");
	scanf("%s",&mp);
	
	
		float AM;
		printf("Enter Atomic Mass :");
	scanf("%f",&AM);
	
	int P;
		printf("Enter period :");
	scanf("%d",&P);
		int G;
		printf("Enter Group");
	scanf("%d",&G);
	
		int name[20];
	printf("Enter Name of element :");
	scanf("%s",&name);
	
	
	char sym[10];
	printf("Enter Symbol of element :");
	scanf("%s",&sym);
	new_insert( name,  sym, AN,  AM,  G,  P,  st,  val,  bp,  mp,  ar,  ec);
		    break;


         case 4:
         	
         	printf("enter the element atomic number for deletion :");
         	scanf("%d",&number);
          delete(number);
            break;
            
        case 5:
            return;
            break;

        default:
            printf("Invalid Input");
            break;
        }
    }
    
    
}

}

