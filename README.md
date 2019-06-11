object colectivo{
const cisterna=1000
const limitedepasajeros=50
var combustible=1000
var pasajeros=0
var ganancia=0
var parada=0
var direccion=1

method avanzar(){
	if (combustible<10){
		return 'no queda combustible'
	}
	else{
		if(parada==0){       //Si la parada del colectivo es 0(salida) ira en dirección 1 que sería el camino hacia la terminal 
		direccion=1  //(parada5)
		}	             
		if(parada==5){
			direccion=2   //Si la parada es 5 la dirección cambiaria a 2 , haciendo que ahora se pueda volver a la 
		}                     //parada 0 (salida).
		if(direccion==1){  
			parada+=1   //Si dirección es igual 1 se le suma 1 a  parada. Debido a esto solo se podrá viajar de 1 parada a 
		}                   //la siguiente y no adelantarse 2 o 3 paradas. 
		else{
			parada-=1
		}
		parada0.paradaact(parada) // Va a chequear si el colectivo esta en la parada indicada y bajar a los pasajeros 
		parada1.paradaact(parada) // que indicaron esa parada
		parada2.paradaact(parada)
		parada3.paradaact(parada)
		parada4.paradaact(parada)
		parada5.paradaact(parada)
		combustible-=(10+(0.2*pasajeros)) // El tanque consumira 10 L por cada parada + 0.2 L por cada pasajero subido
		return parada
	}
}
method estado(){  // muestra la cantidad de pasajeros en el momento
	return ' tanque: '+combustible+' ganancia: '+ganancia+' pasajeros totales: '+pasajeros
}
	method cargarcombustible(){
	if(parada==5){                                     //Al estar en la parada 5(terminal) se puede cargar el combustible 
		if(ganancia>((cisterna-combustible)*2)){ //con la ganancia del recorrido cobrando la cantidad de litros 	
		ganancia-=((cisterna-combustible)*2)     //necesaria para cargar el tanque. 
		combustible=cisterna
		return 'tanque cargado'
		}
		else{
			ganancia-=((((cisterna-combustible)*2)/ganancia)*2)
			return 'cargamos '+(((cisterna-combustible)*2)/ganancia)+'litros, por que no tenemos ganacia suficiente'
		}
	}
	else{
		
		return 'no estamos en la parada 5'
	}
}
	
	
method dinero(){   // Nombre que puede ser cambiado aca va a ir todo lo que tenga que ver con ganancia
	
	
}


method subir(destino){	
	if((pasajeros == limitedepasajeros){
	return 'No pueden subir mas'  //Chequea la cantidad de pasajeros parados y sentados para comprobar si llego al límite de 
	}                            //capacidad, en caso de estar el limite mostrara el mensaje de “no pueden subir mas“. 
	else{
        destino.persqbajan()  //En caso de haber espacio dentro del colectivo se tendrá que indicar la parada del pasajero
	pasajeros+=1         // y este destino se almacenara en la variable parada que indique(1,2,3,etc).
   } 
	if (parada==4){
	ganancia+=5   //En base la parada elegida se cobrara 20$ o 5$ al pasajeroy almacenar la cantidad en la variable ganancia.
	}
	else{
	ganancia+=20
	}
	return pasajeros
	}
	

method bajar(cantpersqbajan){
	pasajeros-=cantpersqbajan    // Resta la cantidad de personas dentro del colectivo con las que se bajaron
}

object parada0{
	var persbajan=0
	var paradactualdcolect=0
method persqbajan(){
	persbajan+=1 //Suma la cantidad de pasajeros que avisan al conductor que van a bajar (Tocan timbre)
	}
method cantllegados(){ //Muestra la cantidad de personas que van a bajar.
	return persbajan
}
method subir(destino){ //Se le indica el destino al conductor
	     return 'no pueden subir pasajeros en la parada0'
}
method bajar(){ //Baja a las personas que previamente avisaron que querían bajar (Abren las puertas y bajan)
	if(paradactualdcolect==0){
		colectivo.bajar(persbajan)
		persbajan-=persbajan
		return 'bajaron pasajeros'
	}
	else{
		return 'el colectivo no esta en la parada 0'
	}

}

method paradaact(paradact){ //Me muestra en qué parada estoy
	paradactualdcolect=paradact	
	return self.bajar()
}

}
object parada1{
	var	persbajan=0
	var paradactualdcolect=0
method persqbajan(){
	persbajan+=1
	}
method cantllegados(){
	return persbajan
}
method subir(destino){
	if(destino==self){
		return 'no puede bajarse en la misma parada'
	}
	else{
		if(paradactualdcolect==1){
		return colectivo.subir(destino)
	}
	else{
		return 'el colectivo no esta en la parada 1'
	}
	}
}
method bajar(){
	if(paradactualdcolect==1){
		colectivo.bajar(persbajan)
		persbajan-=persbajan
		return 'bajaron pasajeros'
	}
	else{
		return 'el colectivo no esta en la parada 1'
	}	
}
method paradaact(paradact){
	paradactualdcolect=paradact
	return self.bajar()
}
}
object parada2{
	var	persbajan=0
	var paradactualdcolect=0
method persqbajan(){
	persbajan+=1
	}
method cantllegados(){
	return persbajan
}
method subir(destino){
	if(destino==self){
		return 'no puede bajarse en la misma parada'
	}
	else{
		if(paradactualdcolect==2){
		return colectivo.subir(destino)
	}
	else{
		return 'el colectivo no esta en la parada 2'
	}
	}
}
method bajar(){
	if(paradactualdcolect==2){
		colectivo.bajar(persbajan)
		persbajan-=persbajan
		return 'bajaron pasajeros'
	}
	else{
		return 'el colectivo no esta en la parada 2'
	}
}
method paradaact(paradact){
	paradactualdcolect=paradact
	return self.bajar()
}
}
object parada3{
	var	persbajan=0
	var paradactualdcolect=0
method persqbajan(){
	persbajan+=1
	}
method cantllegados(){
	return persbajan
}
method subir(destino){
	if(destino==self){
		return 'no puede bajarse en la misma parada'
	}
	else{
		if(paradactualdcolect==3){
		return colectivo.subir(destino)
	}
	else{
		return 'el colectivo no esta en la parada 3'
	}
	}
}
method bajar(){
	if(paradactualdcolect==3){
		colectivo.bajar(persbajan)
		persbajan-=persbajan
		return 'bajaron pasajeros'
	}
	else{
		return 'el colectivo no esta en la parada 3'
	}
}
method paradaact(paradact){
	paradactualdcolect=paradact
	return self.bajar()
}
}
object parada4{
	var	persbajan=0
	var paradactualdcolect=0
method persqbajan(){
	persbajan+=1
	}
method cantllegados(){
	return persbajan
}
method subir(destino){
	if(destino==self){
		return 'no puede bajarse en la misma parada'
	}
	else{
		if(paradactualdcolect==4){
		return colectivo.subir(destino)
	}
	else{
		return 'el colectivo no esta en la parada 4'
	}
	}
}
method bajar(){
	if(paradactualdcolect==4){
		colectivo.bajar(persbajan)
		persbajan-=persbajan
		return 'bajaron pasajeros'
	}
	else{
		return 'el colectivo no esta en la parada 4'
	}	
}
method paradaact(paradact){
	paradactualdcolect=paradact
	return self.bajar()
}
}
object parada5{
	var	persbajan=0
	var paradactualdcolect=0
method persqbajan(){
	persbajan+=1
	}
method cantllegados(){
	return persbajan
}
method subir(destino){
	if(destino==self){
		return 'no puede bajarse en la misma parada'
	}
	else{
		if(paradactualdcolect==5){
		return colectivo.subir(destino)
	}
	else{
		return 'el colectivo no esta en la parada 5'
	}
	}
}
method bajar(){
	if(paradactualdcolect==5){
		colectivo.bajar(persbajan)
		persbajan-=persbajan
		return 'bajaron pasajeros'
	}
	else{
		return 'el colectivo no esta en la parada 5'
	}
}
method paradaact(paradact){
	paradactualdcolect=paradact
return self.bajar()
}
}
