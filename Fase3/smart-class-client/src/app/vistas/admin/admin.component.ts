import { Component, OnInit } from '@angular/core';
import { FormControl,FormGroup,Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { ApiService } from 'src/app/servicios/api/api.service';

import {MasivaI} from '../../modelos/masiva.interface';

@Component({
  selector: 'app-admin',
  templateUrl: './admin.component.html',
  styleUrls: ['./admin.component.css']
})
export class AdminComponent implements OnInit {

  chargueForm= new FormGroup({

    dato_text_Area:new FormControl('',Validators.required)

  })

  constructor(private api:ApiService,private router:Router) { }

  ngOnInit(): void {
  }

  op:number=1;

  
  upLoadEstudents(carga_masiva:MasivaI){

   

   this.api.masiveUsers(carga_masiva).subscribe(data=>{

      if(data.status == 'ok'){

        alert("La carga masiva se produjo exitosamente")
        
      }else{

        if(data.status=='error'){

          alert(data.result)
        }
      }
   })
   this.chargueForm.controls['dato_text_Area'].setValue("")

   

  }

  upLoadPensum(carga_masiva:MasivaI){

    this.api.masivePensum(carga_masiva).subscribe(data=>{

      if(data.status == 'ok'){

        alert("la carga masiva de pensum se produjo exitosamente")
      }else{

        alert("hubo un error al cargar los cursos del pensum")
      }
    })

    this.chargueForm.controls['dato_text_Area'].setValue("")
  }
  cursosEstudiant(carga_masiva:MasivaI){

    this.api.masiveCursoEstudiant(carga_masiva).subscribe(data=>{

      if(data.status=='ok'){

        alert("se ha cargado los cursos del estudiante")
      }
    })

    this.chargueForm.controls['dato_text_Area'].setValue("")
  }
  
  upLoadApuntes(carga_masiva:MasivaI){

    this.api.masiveApuntes(carga_masiva).subscribe(data=>{

      if(data.status == 'ok'){

        
        alert(data.result)
      }else{

        if(data.status=='error'){

          alert(data.result)
        }
      }
    })

    this.chargueForm.controls['dato_text_Area'].setValue("")
  }

  getReporteCero(){

    this.api.reprote0().subscribe(data=>{
 
       if(data.status=='ok'){
 
         alert("se ha generado el Reporte de estudiantes correctamente");
       }
 
    })
   }

   getReporteCinco(){

    this.api.reprote5().subscribe(data=>{
 
       if(data.status=='ok'){
 
         alert("se ha generado el Reporte de estudiantes correctamente");
       }
 
    })
   }

   generarReporteseis(){

    this.api.reporte6().subscribe(data=>{

      if(data.status=='ok'){

        alert(data.result)
      }else{

        if(data.status=='error'){
          alert(data.result)
        }
      }
    })
   }


   cerrarSesion(){

    localStorage.clear()
    this.router.navigate(['login'])
   }
 

}
