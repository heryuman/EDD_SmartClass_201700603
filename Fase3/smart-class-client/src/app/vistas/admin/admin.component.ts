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
      }
   })

  }

  upLoadPensum(carga_masiva:MasivaI){

    this.api.masivePensum(carga_masiva).subscribe(data=>{

      if(data.status == 'ok'){

        alert("la carga masiva de pensum se produjo exitosamente")
      }
    })
  }

  getReporteCero(){

   this.api.reprote0().subscribe(data=>{

      if(data.status=='ok'){

        alert("se ha generado el Reporte de estudiantes correctamente");
      }

   })
  }

}
