 #ifndef PERSONA_H
 #define PERSONA_H
 #include<vector>

using namespace std;

class Persona {
   public:
      Persona( long );
      ~Persona();
      void Display( char * );
     vector < int > solicitud(char * rotulo);
     private:
      long idPersona;
      unsigned int pisoDondeMeSubo, pisoDondeMeBajo;

};

#endif // PERSONA_H
