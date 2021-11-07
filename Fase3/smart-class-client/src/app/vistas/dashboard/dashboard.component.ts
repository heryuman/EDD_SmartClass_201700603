import { Component, OnInit } from '@angular/core';
import { FormControl,FormGroup,Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { ApunteI } from 'src/app/modelos/apunte.inteface';
import { lista_apuntesI } from 'src/app/modelos/lista_apuntes.interface';
import { ApiService } from 'src/app/servicios/api/api.service';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.css']
})
export class DashboardComponent implements OnInit {
public carnet:string=this.getCarnet();
public nombre:string="";
public apuntes!: lista_apuntesI[];
op:number=1
apunte:number=0;
contadorApuntes=0;

  constructor(private api:ApiService,private router:Router) { }

  getCarnet():string{
    let dato= localStorage.getItem('token_user')
    let estudiante
    if(dato !=null){
     estudiante=JSON.parse(dato)
     return estudiante['carnet']
    }else{

      return '0'
    }

  }

  ngOnInit(): void {

    let car=`{carnet:${this.carnet}}`

    this.api.getListaApuntes(this.carnet).subscribe(data=>{

      console.log(data)
      this.apuntes=data;
    })
  }
  apunteForm= new FormGroup({
    
    carnet: new FormControl(this.carnet,Validators.required),
    titulo: new FormControl('',Validators.required),
    contenido: new FormControl('',Validators.required)
 })
 

  upApunte(apunte:ApunteI){
  
    let dato= localStorage.getItem('token_user')
    let estudiante
    if(dato !=null){
     estudiante=JSON.parse(dato)
     let carnet=estudiante['carnet']
     alert(carnet)
     this.apunteForm
    }

    
    
    this.api.sendApunte(apunte).subscribe(data=>{

      if (data.status=='ok'){

        alert(data.result)
      }

    })
  }

  listaApunte(){
    let car=`{carnet:${this.carnet}}`

    this.api.getListaApuntes(this.carnet).subscribe(data=>{

      console.log(data)
      this.apuntes=data;
    })
  
  }

  cerrarSesion(){

    localStorage.clear()
    this.router.navigate(['login'])
   }

}
