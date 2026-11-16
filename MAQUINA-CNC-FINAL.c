#include <16F877A.h>
#fuses XT, NOWDT
#use delay (clock = 4 Mhz)
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7)

#use standard_io(B)
#use standard_io(C)
#use standard_io(D)

///////////////////////////////////////////////////////////////////////////////

int uni=0,bi=0,drn=1,drm=1;
signed int v=7, u=7, servo=3;
signed int pasosu[8] = {9,8,10,2,6,4,5,1};
signed int pasosb[8] = {9,8,10,2,6,4,5,1};

int16 con1,con2;
int estado=100, pos=0,val=0, val2=1;
signed int x=7, j=7, letras=0;
signed int pasos1[8] = {9,8,10,2,6,4,5,1};
signed int pasos2[8] = {9,8,10,2,6,4,5,1};
int32 pasosX_totales = 0;
int32 pasosY_totales = 0;

///////////////////////////////////////////////////////////////////////////////

void regresar_a_cero() {
   int32 s=0,d=0;

   for (s = 0; s < pasosX_totales; s++) {
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x == 8) x = 0;
   }
   for (d = 0; d < pasosY_totales; d++) {
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x == 8) x = 0;
   }
   pasosX_totales = 0;
   pasosY_totales = 0;
}

void mover_servo(int16 ancho) {
   output_high(PIN_E0);
   delay_us(ancho);
   output_low(PIN_E0);
   delay_us(20000 - ancho);
}

void regreso_a(){
   for (con2=0;con2<(1600);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(1000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   
}

void regreso_e(){
      for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con1=0;con1<(1000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(1000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
}

void regreso_i(){
      for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
      for (con2=0;con2<(750);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
      for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
      for (con2=0;con2<(750);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }  
      for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
}

void regreso_o(){
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
}

void regreso_u(){
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
}

void letra_a (){

   for (j = 0; j < 50; j++){
      mover_servo(2000);
   }
   
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000); // 1 ms
   }
   for (con1=0;con1<(1000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(2000); // 1 ms
   }
   for (con2=0;con2<(1600);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
         for (j = 0; j < 50; j++) {
         mover_servo(1000); // 1 ms
         }
}

void letra_i (){
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
   for (con2=0;con2<(750);con2++){
   output_D(pasos2[x]);
   delay_ms(1);
   x++;
   if (x==8)
      x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (j = 0; j < 50; j++) {
   mover_servo(1000); // 1 ms
   }
   for (con2=0;con2<(750);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
      x=7;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
}

void letra_e (){
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
   for (con1=0;con1<(1000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
   for (con1=0;con1<(1000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
}

void letra_o (){
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
}

void letra_u (){
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x--;
      if (x==-1)
         x=7;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
   for (con2=0;con2<(1500);con2++){
      output_D(pasos2[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(2000);
   }
   for (con1=0;con1<(2000);con1++){
      output_B(pasos1[x]);
      delay_ms(1);
      x++;
      if (x==8)
         x=0;
   }
   for (j = 0; j < 50; j++) {
      mover_servo(1000);
   }
}

///////////////////////////////////////////////////////////////////////////////

#INT_RDA
void inteRDA(){
   estado = getc();
   
   //posiciones
   if (estado == 0)
      pos = 1;
      //posicion 1
   if (estado == 1)
      pos = 2;
      //posicion 2
   if (estado == 2)
      pos = 3;
      //posicion 3
   if (estado == 3)
      pos = 4;
      //posicion 4
   if (estado == 4)
      pos = 5;
      //posicion 5
   if (estado == 5)
      pos = 6;
      //posicion 6

///////////////////////////////////////////////////////////////////////////////

      //letras
   if (estado == 6)
      letras = 1;
      //letra A
   if (estado == 7)
      letras = 2;
      //letra E
   if (estado == 8)
      letras = 3;
      //letra I
   if (estado == 9)
      letras = 4;
      //letra O
   if (estado == 10)
      letras = 5;
      //letra U

 //////////////////////////////////////////////////////////////////////////////
   
   //control de motores
   if (estado == 11 && drn == 1){
      bi=2;
      drn = 0;
   }
   if (estado == 12 && drn == 0){
      bi=3;
      drn = 1;
   }
   if (estado == 13 && drn == 1){
      bi=1;
      drn = 0;
   }
   if (estado == 14 && drm == 1){
      uni=2;
      drm = 0;
   }
   if (estado == 15 && drm == 0){
      uni=3;
      drm = 1;
   }
   if (estado == 16 && drm == 1){
      uni=1;
      drm = 0;
   }
   
///////////////////////////////////////////////////////////////////////////////
   
   //servo
   if (estado == 17){
   servo = 1;
   }
   if (estado == 18){
   servo = 0;
   }
}

///////////////////////////////////////////////////////////////////////////////

void main (){
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   
   output_B(0);
   output_D(0);
   
///////////////////////////////////////////////////////////////////////////////
   
   while (true){

      //posicion 1
      if (pos == 1 && val == 0){
         pasosX_totales = 580;
         pasosY_totales = 500;
         
         for (con1=0; con1<(580); con1++){
               output_B(pasos1[x]);
               delay_ms(1);
               x--;
               if (x==-1)
               x=7;
         }
         for (con2=0; con2<(500); con2++){
            output_D(pasos2[x]);
            delay_ms(1);
            x--;
            if (x==-1)
            x=7;
         }
         
      val=1;
      val2=0;
      pos = 0;
      } 
      
      //posicion 2
      if (pos == 2 && val == 0){
         pasosX_totales = 4060;
         pasosY_totales = 500;
         
         for (con1=0; con1<(580*7); con1++){
               output_B(pasos1[x]);
               delay_ms(1);
               x--;
               if (x==-1)
               x=7;
         }
         for (con2=0; con2<(500); con2++){
            output_D(pasos2[x]);
            delay_ms(1);
            x--;
            if (x==-1)
            x=7;
         }
         val = 1;
         val2=0;
         pos = 0;
      }
      
      //posicion 3
      if (pos == 3 && val == 0){
         pasosX_totales = 7540;
         pasosY_totales = 500;
         
         for (con1=0; con1<(580*13); con1++){
               output_B(pasos1[x]);
               delay_ms(1);
               x--;
               if (x==-1)
               x=7;
         }
         for (con2=0; con2<(500); con2++){
            output_D(pasos2[x]);
            delay_ms(1);
            x--;
            if (x==-1)
            x=7;
         }
         val = 1;
         val2=0;
         pos = 0;
      }
      
      //posicion 4 
      if (pos == 4 && val == 0){
         pasosX_totales = 580;
         pasosY_totales = 4000;
         
         for (con1=0; con1<(580); con1++){
               output_B(pasos1[x]);
               delay_ms(1);
               x--;
               if (x==-1)
               x=7;
         }
         for (con2=0; con2<(500*8); con2++){
            output_D(pasos2[x]);
            delay_ms(1);
            x--;
            if (x==-1)
            x=7;
         }
         val = 1;
         val2=0;
         pos = 0;
      }
      
      //posicion 5
      if (pos == 5 && val == 0){
         pasosX_totales = 4060;
         pasosY_totales = 4000;
         
         for (con1=0; con1<(580*7); con1++){
               output_B(pasos1[x]);
               delay_ms(1);
               x--;
               if (x==-1)
               x=7;
         }
         for (con2=0; con2<(500*8); con2++){
            output_D(pasos2[x]);
            delay_ms(1);
            x--;
            if (x==-1)
            x=7;
         }
         val = 1;
         val2=0;
         pos = 0;
      }
      
      //posicion 6
      if (pos == 6 && val == 0){
         pasosX_totales = 7540;
         pasosY_totales = 4000;
         
         for (con1=0; con1<(580*13); con1++){
               output_B(pasos1[x]);
               delay_ms(1);
               x--;
               if (x==-1)
               x=7;
         }
         for (con2=0; con2<(500*8); con2++){
            output_D(pasos2[x]);
            delay_ms(1);
            x--;
            if (x==-1)
            x=7;
         }
         val = 1;
         val2=0;
         pos = 0;
      }

///////////////////////////////////////////////////////////////////////////////

      //letra A
      if (letras == 1 && val2 == 0){
         letra_a();
         val2=1;
         val=0;
         letras=0;
         regreso_a();
         regresar_a_cero ();
         reset_cpu();
         break;
      }
      //letra E
      if (letras == 2 && val2 == 0){
         letra_e();
         val2=1;
         val=0;
         letras=0;
         regreso_e();
         regresar_a_cero ();
         reset_cpu();
         break;
      }
      //letra I
      if (letras == 3 && val2 == 0){
         letra_i();
         val2=1;
         val=0;
         letras=0;
         regreso_i();
         regresar_a_cero ();
         reset_cpu();
         break;
      }
      //letra O
      if (letras == 4 && val2 == 0){
         letra_o();
         val2=1;
         val=0;
         letras=0;
         regreso_o();
         regresar_a_cero ();
         reset_cpu();
         break;
      }
      //letra U
      if (letras == 5 && val2 == 0){
         letra_u();
         val=1;
         val=0;
         letras=0;
         regreso_u();
         regresar_a_cero ();
         reset_cpu();
         break;
      }

///////////////////////////////////////////////////////////////////////////////    
      
      if (bi == 3){ //PARO
         output_b(0);
      }
      
      if(bi == 2){ //DERECHA
         output_b(pasosb[u]);
         delay_ms(2);
         u++;
         if (u == 8){
            u=0;
         }
      }
      
      if (bi == 1){ //IZQUIERDA
         output_b(pasosb[u]);
         delay_ms(2);
         u--;
         if (u == -1){
            u=7;
         }
      }
      
      if (uni == 3){ //PARO
         output_d(0);
      }
      
      if (uni == 1){ //DERECHA
         output_d(pasosu[v]);
         delay_ms(2);
         v++;
         if (v == 8){
            v=0;
         }
      }
      
      if (uni == 2){ //IZQUIERDA
         output_d(pasosu[v]);
         delay_ms(2);
         v--;
         if (v == -1){
            v=7;
         }
      }
      
///////////////////////////////////////////////////////////////////////////////

      //servo arriba
      if (servo == 1){
         for (j = 0; j < 50; j++){
            mover_servo(1000);
         }
         reset_cpu();
         break;
      }
      
      //servo abajo
      if (servo == 0){
         for (j = 0; j < 50; j++){
            mover_servo(2000);
         }
         reset_cpu();
         break;
      }
   }
}
