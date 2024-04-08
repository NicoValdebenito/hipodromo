#ifndef CABALLO_HPP
#define CABALLO_HPP

class Caballo {
    private:
        int posicionCaballo; // posición actual del caballo
    
    public:
        Caballo(); // constructor de la clase
        void MoverCaballo();
        void setPosicion(int posicion);     
        int getPosicion();  
        bool verificarGanador();
        ~Caballo();
};

#endif