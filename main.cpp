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
    int combinaisons[] = {455,732,297,913,139};
    string phrase;
    string fc_abracadabra = "void abracadabra(int x, int &y) {\nx+=2;\ny+=5;\n}\n\n";
    string Personnages[4] = {"Personnage 1","Personnage 2","Personnage 3","Personnage 4"};
    string str;

    do {
        cout << "\nCet escape game se joue a quatre personnes, chacun incarnant un personnage different."
                "\nLa plupart des enigmes ont un rapport avec le C++ ou la programmation."
                "\nVous devrez cooperer pour venir a bout de cette epreuve.\n"
                "Hormis enigmes de type code, les reponses a entrer ne comportent jamais de majuscule\n";
        cout<<"\nQuel personnage voulez-vous incarner ?\n\n1: Personnage 1\n2: Personnage 2\n3: Personnage 3\n4: Personnage 4\n";
        cin>>choix;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while(choix<1 || choix>4);
    cout<< "\nBienvenue, "<<Personnages[choix-1]<<endl;
    cout << "\nLorsque la machine attend une reponse, vous pouvez la saisir et appuyer sur entree,"
            " ou simplement appuyer sur entree pour revenir"
            " au menu principal de votre personnage\n\n";
    while(escape_termine == 0) {
        switch (choix) {
        case 1://Programme principal joueur 1--------------------------------------------------
            faire_action("\n\nQue voulez-vous examiner ?\n1 : Terminal poussiereux\n"
                         "2 : Terminal enigmatique\n"
                         "3 : Grand tableau cadenasse\n"
                         "4 : Message ecrit a la craie\n\n", action);
            switch (action) {
            case 1:
                action = 0; //remise a 0 pour pouvoir rechoisir action au prochain loop
                //ENIGME 1.1 #####################################
                cout << "\nLe terminal affiche le message suivant : "
                        "\n\nSoit une classe A, donner oh#surwrw|sh#gh#od#phwkrgh (3) qui surcharge l’operateur + "
                        "avec un argument de type A nomme a : (Entrez votre reponse)\n"
                        "(Taper Entree pour quitter le terminal)\n\n" << endl;
                entrer_reponse("A operator+(A a);", "\n\nLe terminal emet un bip et vous renvoie le message"
                                                    "suivant : XX = 33\n\n");
                break;
                //#####################################
            case 2:
                action = 0;
                //ENIGME 1.2 ###############################
                cout << "La racine du r~xyjwj (5) ?\n"
                        "(Entrez votre reponse)\n\n"; //La racine du mystere
                entrer_reponse("13", "Mot a crypter : \"heritage\" (~...~) L'inscription entre"
                                     " parentheses a ete raturee, elle est illisible...\n\n"); //code coffre fort
                break;
                //########################################
            case 3:
                action = 0;
                //ACCES TABLEAU FINAL 1.3 ###############################
                cout << "\nUn grand tableau est muni de 5 cadenas a chiffres... Pour l'instant, les combinaisons sont :\n\n";
                for (int i=0;i<5;i++) cout << tableau_final[i] <<" " <<endl;
                cout << "\nQuelle combinaison modifier ? (1, 2 ,3, 4, 5) Sinon, Entrez 0 \n";
                cin>>k;
                cin.clear();
                cin.ignore(10000, '\n');
                if(k>0 && k<6) {
                    cout << "Quelle combinaison voulez-vous entrer ?\n";
                    cin >> tableau_final[k-1];
                    if(tableau_final[k-1] == combinaisons[k-1]) {
                        cout << "\n\nVous percevez les cliquetis de ce qui semble être un complexe mecanisme"
                                " de verrouillage. Cette combinaison doit être correcte ! \n\n";
                    }
                    else {
                        cout << "\n\nHmm... Rien ne se passe...\n\n";
                    }
                }
                if(tableau_final[0] == 455 && tableau_final[1]==732 && tableau_final[2] == 297 && tableau_final[3]==913 && tableau_final[4]==139)
                {
                    cout << "\nBravo ! Vous êtes arrive au bout et avez decouvert le tresor cache derriere"
                            "le tableau : toute notre estime !\n"
                            "Quelle equipe vous faites !\n\n";
                    escape_termine = 1;
                }
                break;
                //########################################
            case 4:
                action = 0;
                //ENIGME 1.4 ###############################
                cout << "\nVous trouvez un message ecrit a la va vite sur un mur :\n"
                        "Le coffre fort accepte cet animal crypte : 51°50'54.5\"N 0°XX'16.5\"W (7)\n\n"
                        "(Certains chiffres (XX) ont ete ratures...)\n\n"; //coordonnees GPS : mot = lion
                break;
                //########################################

            }


            break;//---------------------------------------------------------------------------
        case 2://Programme principal joueur 2--------------------------------------------------

            faire_action("\n\nQue voulez-vous examiner ?\n"
                         "1 : Terminal de decryptage\n"
                         "2 : Ordinateur degrade\n"
                         "3 : Afficheur numerique\n\n", action);
            switch (action) {
            case 1:
                action = 0;
                //ACCES FONCTION DECODE 2.1 ###############################
                //Donner au joueur la possibilite d'utiliser la fonction decode
                cout << "\nVous vous installez au poste de cryptage. Il semble necessiter une phrase a crypter ainsi"
                        " qu'une cle de cryptage numerique...\n\n";
                cout << "Terminal de decryptage... veuillez entrer la phrase cryptee :\n";
                getline(cin,str);
                if (str=="") break; //Annule si appui sur entree
                cout << "Terminal de decryptage... veuillez entrer la cle de cryptage :\n";
                cin>>cle_cryptage;
                cin.clear();
                cin.ignore(10000, '\n');
                decryptage(str,cle_cryptage);

                break;
                //########################################
            case 2:
                action = 0;
                //ENIGME 2.2 ###############################
                cout << "\n\nL'ordinateur, obsolete mais joueur, vous nargue d'un ecran bloque sur une enigme, "
                        "comme un ultime pied de nez lance sur un ton de defi avant sa mise a la casse\n\n"
                        "Contrairement a un pointeur,"
                        "une ylmlylujl (7) requiert une etape indispensable lors de sa kljshyh{pvu (7), "
                        "quelle est-elle ?\n"
                        "\n(Vous pourriez utiliser le grimoire des anciens notecpp.pdf pour y "
                        "trouver l'incantation necessaire...)\n\n"
                        "(Entrer votre reponse)\n\n";
                entrer_reponse("initialisation", fc_abracadabra); //Donne la fonction abracadra pour avancer enigme 3.1

                break;
                //########################################
            case 3:
                action = 0;
                //ENIGME 2.3 ###############################
                cout << "Un viel appareil a cristaux liquides affiche ce curieux dialecte sur son unique ligne :\n\n"
                        "\n#####################################################################"
                        "\n#   int mystere = vec[0]*vec[2]+ *(vec+3)*(*(vec+4)) +3*vec[1]*7;   #"
                        "\n#####################################################################\n\n";//=169

                break;
                //########################################
            }
            break;//---------------------------------------------------------------------------

        case 3://Programme principal joueur 3--------------------------------------------------
            faire_action("\n\nQue voulez-vous examiner ?\n"
                         "1 : Terminal mystique\n"
                         "2 : Cadenas numerique avec message\n"
                         "3 : Coffre fort\n\n", action);
            switch (action) {
            case 1:
                action = 0;
                //ENIGME 3.1 ###################################
                cout << "int a=2;" << endl <<"int b=3;" << endl << "int * pt = &a;"
                     << endl << "abracadabra(*pt, b);"
                         << endl << "(*pt)++;" << endl << "b--;"
                         << endl << "cout << (*pt)*(*pt)*b; //Quelle valeur est affichee ?"
                         << endl << endl;
                entrer_reponse("54", "\nLe terminal se deverrouille et une boite mail apparait."
                                     "\n\n------------------------------------------------------------"
                                     "\nDear all,"
                                     "\nPlease find below one of the passwords for the safe"
                                     "\n\npassword : \"reference\" (-4)"
                                     "\n\n\nRemember to encrypt it before use"
                                     "\n\nBest regards,"
                                     "\nThe Director\n\n"
                                     "\n\n------------------------------------------------------------");

                break;
                //#############################################
            case 2:
                action = 0;
                //ENIGME 3.2 ###################################
                cout << "Je suis un symbole de Protection" << endl;
                entrer_reponse("#", "Mot a crypter : \"protected\" (1)\n\n");

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
            faire_action("\n\nQue voulez-vous examiner ?\n1 : Message sur le mur avec clavier d'ordinateur\n"
                         "2 : cle usb avec un programme\n"
                         "3 : Terminal de cryptage \n\n", action);
            switch (action) {
            case 1:
                action = 0;
                //ENIGME 4.1 ###############################
                cout << "\n\nI am the top left hand corner key on a regular keyboard."
                        "\nMy full name, once encrypted, is... ? (11) ?\n"
                        "(Entrez votre reponse)\n\n";
                entrer_reponse("p~nl{p", "Un dessin apparait et vous "
                                         "invite a utiliser un coffre fort muni de ce code..."
                                         "\nDe plus, quelqu'un a griffonne ceci sur un bout de papier : (9)\n\n");

                break;
                //########################################
            case 2:
                action = 0;
                //ENIGME 4.2 ###############################
                cout << "\n\nVous trouvez le programme suivant sur la cle usb : "
                        "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                        "\n\nint vec[5] = {1,2,3,4,5};\nvec[3] = "
                        "*(vec+1)*vec[vec[3]]**vec+1;\nvec[2] = *(vec+vec[1]+2)+1;\nvec[*(vec)-1] = "
                        "*vec*(*vec+1)**(vec+2);\nfor(int i=0;i<5;i++) cout << vec[i] << endl;\n\n"
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

                break;
                //########################################
            case 3:
                action = 0;
                //ACCES FONCTION CODE 4.3 ###############################
                //Donner au joueur la possibilite d'utiliser la fonction CODE
                cout << "\nVous vous installez au poste de cryptage. Il semble necessiter une phrase a crypter ainsi"
                        " qu'une cle de cryptage numerique...\n\n";
                cout << "Terminal de cryptage... veuillez entrer la phrase a crypter : \n\n";
                getline(cin,str);
                if (str=="") break; //Annule si appui sur entree
                cout << "Terminal de cryptage... veuillez entrer la cle de cryptage : \n\n";
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
    cout << "Le coffre fort dispose de cinq compartiments...\n"
            "Sur sa façade, un clavier de lettres et caracteres, depourvu de chiffres\n\n"
            "Veuillez entrer un code : ";
    string a;
    getline(cin, a);
    if(a == "qspufdufe") { cout << "\n\nLe premier compartiment s'ouvre ! Il y a un message a l'interieur : 1 --> 455\n\n";} //protected
    else if (a == "p~nl{p") {cout << "\n\nLe deuxieme compartiment s'ouvre ! Il y a un message a l'interieur : 2 --> 732\n\n";} //escape
    else if (a == "jgtkvcig") {cout << "\n\nLe troisieme compartiment s'ouvre ! Il y a un message a l'interieur : 3 --> 297\n\n";}//heritage
    else if (a == "spvu") {cout << "\n\nLe quatrieme compartiment s'ouvre ! Il y a un message a l'interieur : 4 --> 913\n\n";}//lion
    else if (a == "nabanaj_a") {cout << "\n\nLe cinquieme compartiment s'ouvre ! Il y a un message a l'interieur : 5 --> 139\n\n";}//reference
    else cout << "\n\nRien ne se passe...\n\n";

}

void cryptage(string txt, int c)
{
  unsigned long length = txt.length();
  char tab[length];
cout << "Phrase cryptee : ";
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
cout << "Phrase decryptee : ";
  for (int i = 0; i < length; i++) {
          tab[i] = txt[i]-c;
          cout << tab[i];
   }
  cout << endl;
}

