import { Component, OnInit } from '@angular/core';
import { FormGroup,FormControl,Validators } from '@angular/forms';

import { ApiService } from 'src/app/servicios/api/api.service';
import { RegisterI } from 'src/app/modelos/register.interface';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {

  registerForm=new FormGroup({

    carnet:new FormControl('',Validators.required),
    dpi : new FormControl('',Validators.required),
    nombre: new FormControl('',Validators.required),
    carrera: new FormControl('',Validators.required),
    correo: new FormControl('',Validators.required),
    password: new FormControl('',Validators.required),
    edad: new FormControl('',Validators.required)
  })

  constructor(private api:ApiService,private router:Router) { }

  ngOnInit(): void {
  }

  onRegister(form:RegisterI){

    this.api.registerUser(form).subscribe(data=>{

      if(data.status=='ok'){
        
        alert("Registro completado Exitosamente")
        this.router.navigate(['login']);

      }else{

         if(data.status=='error'){

          alert(data.result)
         }
      }
    })

  }

}
