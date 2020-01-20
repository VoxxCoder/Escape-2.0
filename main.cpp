#include <iostream>
#include <string.h>

using namespace std;

void faire_action(string msg, int &action);
void entrer_reponse(string reponse_juste, string indice);
void cryptage(string txt, int c);
void decryptage(string txt, int c);
void acces_coffre();


int main()
{
    int choix = 0;
    int action = 0;
    int escape_termine=0;
    int cle_cryptage;
    int tableau_final[5] = {0};
    int k;
    string phrase;
    string fc_abracadabra = "void abracadabra(int x, int &y) {\nx+=2;\ny+=5;\n}\n\n";
    string Personnages[4] = {"Personnage 1","Personnage 2","Personnage 3","Personnage 4"};
    string str;

    do {
        cout<<"\nQuel personnage voulez-vous incarner ?\n\n1: Personnage 1\n2: Personnage 2\n3: Personnage 3\n4: Personnage 4\n";
        cin>>choix;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while(choix<1 || choix>4);
    cout<< "\nBienvenue, "<<Personnages[choix-1]<<endl;
    cout << "\nLorsque la machine attend une réponse, vous pouvez simplement appuyer sur entrée pour revenir"
            " au menu principal de votre personnage\n\n";
    while(escape_termine == 0) {
        switch (choix) {
        case 1://Programme principal joueur 1--------------------------------------------------
            faire_action("\n\nVoulez-vous...\n1 : Terminal poussiéreux\n"
                         "2 : Terminal énigmatique\n"
                         "3 : Grand tableau cadenassé\n"
                         "4 : Message écrit à la craie\n\n", action);
            switch (action) {
            case 1:
                action = 0; //remise à 0 pour pouvoir rechoisir action au prochain loop
                //ENIGME 1.1 #####################################
                cout << "Soit une classe A, donner oh#surwrw|sh#gh#od#phwkrgh (3) qui surcharge l’opérateur + "
                        "avec un argument de type A nommé a" << endl;
                entrer_reponse("A operator+(A a);", "XX = 33\n\n");
                break;
                //#####################################
            case 2:
                action = 0;
                //ENIGME 1.2 ###############################
                cout << "La racine du r~xyjwj (5)" << endl << endl; //La racine du mystere
                entrer_reponse("13", "Mot à crypter : \"heritage\" (~...~) L'inscription entre"
                                     " parenthèses a été raturée, elle est illisible...\n\n"); //code coffre fort
                break;
                //########################################
            case 3:
                action = 0;
                //ACCES TABLEAU FINAL 1.3 ###############################
                cout << "\nUn grand tableau est muni de 5 cadenas à chiffres... Pour l'instant, les combinaisons sont :\n";
                for (int i=0;i<5;i++) cout << tableau_final[i] <<" " <<endl;
                cout << "Quelle combinaison modifier ? (1, 2 ,3, 4, 5) Sinon, Entrez 6 \n";
                cin>>k; cout << ":"<< k << endl;
                //if (k=='\r') break; //Retour menu si appui sur entrée
                cin.clear();
                cin.ignore(10000, '\n');
                if(k>=0 && k<6) {
                    cout << "Quelle combinaison voulez-vous entrer ?\n";
                    cin >> tableau_final[k-1];
                }
                if(tableau_final[0] == 455 && tableau_final[1]==732 && tableau_final[2] == 297 && tableau_final[3]==913 && tableau_final[4]==139)
                {
                    cout << "\nBravo !\n";
                    escape_termine = 1;
                }
                break;
                //########################################
            case 4:
                action = 0;
                //ENIGME 1.4 ###############################
                cout << "Merci de coder ceci : 51°50'54.5\"N 0°XX'16.5\"W (7)\n"
                        "(Certains chiffres (XX) ont été raturés...)\n\n"; //coordonnées GPS : mot = lion
                break;
                //########################################

            }


            break;//---------------------------------------------------------------------------
        case 2://Programme principal joueur 2--------------------------------------------------

            faire_action("\n\nVoulez-vous...\n"
                         "1 : Terminal de décryptage\n"
                         "2 : Ordinateur dégradé\n"
                         "3 : Afficheur numérique\n\n", action);
            switch (action) {
            case 1:
                action = 0;
                //ACCES FONCTION DECODE 2.1 ###############################
                //Donner au joueur la possibilité d'utiliser la fonction decode
                cout << "Terminal de décryptage... veuillez entrer la phrase cryptée :\n";
                getline(cin,str);
                if (str=="") break; //Annule si appui sur entrée
                cout << "Terminal de décryptage... veuillez entrer la clé de cryptage :\n";
                cin>>cle_cryptage;
                cin.clear();
                cin.ignore(10000, '\n');
                decryptage(str,cle_cryptage);

                break;
                //########################################
            case 2:
                action = 0;
                //ENIGME 2.2 ###############################
                cout << "Contrairement à un pointeur,"
                        "une référence requiert une étape indispensable lors de sa kljshyh{pvu (7), "
                        "quelle est-elle ?"
                        "\n(Vous pourriez utiliser le grimoire des anciens notecpp.pdf pour y"
                        "trouver l'incantation nécessaire...)" << endl << endl;
                entrer_reponse("initialisation", fc_abracadabra); //Donne la fonction abracadra pour avancer enigme 3.1

                break;
                //########################################
            case 3:
                action = 0;
                //ENIGME 2.3 ###############################
                cout << "\n\nint mystere = vec[0]*vec[2]+ *(vec+3)*(*(vec+4)) +3*vec[1]*7;\n\n"; //=169

                break;
                //########################################
            }
            break;//---------------------------------------------------------------------------

        case 3://Programme principal joueur 3--------------------------------------------------
            faire_action("\n\nVoulez-vous...\n"
                         "1 : Terminal mystique\n"
                         "2 : Cadenas numérique avec message\n"
                         "3 : Coffre fort\n\n", action);
            switch (action) {
            case 1:
                action = 0;
                //ENIGME 3.1 ###################################
                cout << "int a=2;" << endl <<"int b=3;" << endl << "int * pt = &a;"
                     << endl << "abracadabra(*pt, b);"
                         << endl << "(*pt)++;" << endl << "b--;"
                         << endl << "cout << (*pt)*(*pt)*b; //Quelle valeur est affichée"
                         << endl << endl;
                entrer_reponse("54", " Mot à crypter : \"reference\" (-4)");

                break;
                //#############################################
            case 2:
                action = 0;
                //ENIGME 3.2 ###################################
                cout << "Je suis un symbole de Protection" << endl;
                entrer_reponse("#", "Mot à crypter : \"protected\" (1)\n\n");

                break;
                //#############################################
            case 3:
                action = 0;
                //ACCES COFFRE FORT ###################################
                acces_coffre();

                break;
                //#############################################
            }
            break;//---------------------------------------------------------------------------

        case 4://Programme principal joueur 4--------------------------------------------------
            faire_action("\n\nVoulez-vous...\n1 : Message sur le mur avec clavier d'ordinateur\n"
                         "2 : clé usb avec un programme\n"
                         "3 : Terminal de cryptage ?\n\n", action);
            switch (action) {
            case 1:
                action = 0;
                //ENIGME 4.1 ###############################
                cout << "\n\nTop left hand corner keyboard key crypted code ? (11) ?\n";
                entrer_reponse("p~nl{p", "Un dessin apparait et vous "
                                         "invite à utiliser un coffre fort muni de ce code..."
                                         "\nDe plus, quelqu'un a griffonné ceci sur un bout de papier : (~9~)\n\n");

                break;
                //########################################
            case 2:
                action = 0;
                //ENIGME 4.2 ###############################
                cout << "\n\nint vec[5] = {1,2,3,4,5};\nvec[3] = "
                        "*(vec+1)*vec[vec[3]]**vec+1;\nvec[2] = *(vec+vec[1]+2)+1;\nvec[*(vec)-1] = "
                        "*vec*(*vec+1)**(vec+2);\nfor(int i=0;i<5;i++) cout << vec[i] << endl;" << endl << endl;

                break;
                //########################################
            case 3:
                action = 0;
                //ACCES FONCTION CODE 4.3 ###############################
                //Donner au joueur la possibilité d'utiliser la fonction CODE
                cout << "Terminal de cryptage... veuillez entrer la phrase à crypter : \n\n";
                getline(cin,str);
                if (str=="") break; //Annule si appui sur entrée
                cout << "Terminal de cryptage... veuillez entrer la clé de cryptage : \n\n";
                cin>>cle_cryptage;
                cin.clear();
                cin.ignore(10000, '\n');
                cryptage(str,cle_cryptage);
                break;
                //########################################

            }
            break;//---------------------------------------------------------------------------

        }
    }
    return 0;

}
void faire_action(string msg, int &action) {
    do {
        cout << msg << endl;
        cin>>action;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while(action<1 || action>4);
}
void entrer_reponse(string reponse_juste, string indice) {
    string a;
    getline(cin, a);
    if(a==reponse_juste) { cout << indice << endl;}
    else {cout << "Rien ne se passe...\n\n" << endl;}

}
void acces_coffre() {
    cout << "Le coffre fort dispose de cinq compartiments...\nVeuillez entrer un code : ";
    string a;
    getline(cin, a);
    if(a == "qspufdufe") { cout << "\n\nLe premier compartiment s'ouvre ! Il y a un message à l'intérieur : 0 --> 455\n\n";} //protected
    else if (a == "p~nl{p") {cout << "\n\nLe deuxième compartiment s'ouvre ! Il y a un message à l'intérieur : 1 --> 732\n\n";} //escape
    else if (a == "jgtkvcig") {cout << "\n\nLe troisième compartiment s'ouvre ! Il y a un message à l'intérieur : 2 --> 297\n\n";}//heritage
    else if (a == "spvu") {cout << "\n\nLe quatrième compartiment s'ouvre ! Il y a un message à l'intérieur : 3 --> 913\n\n";}//lion
    else if (a == "nabanaj_a") {cout << "\n\nLe cinquième compartiment s'ouvre ! Il y a un message à l'intérieur : 4 --> 139\n\n";}//reference
    else cout << "\n\nRien ne se passe...\n\n";

}

void cryptage(string txt, int c)
{
  unsigned long length = txt.length();
  char tab[length];
cout << "Phrase cryptée : ";
  for (int i = 0; i < length; i++) {
          tab[i] = txt[i]+c;
          cout << tab[i];
   }
  cout << endl;
}

void decryptage(string txt, int c)
{
  int length = txt.length();
  char tab[length];
cout << "Phrase decryptée : ";
  for (int i = 0; i < length; i++) {
          tab[i] = txt[i]-c;
          cout << tab[i];
   }
  cout << endl;
}

