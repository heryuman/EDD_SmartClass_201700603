import { Component, OnInit } from '@angular/core';
import {FormGroup,FormControl,Validators} from '@angular/forms';

import { ApiService } from 'src/app/servicios/api/api.service'; 
import { LoginI } from 'src/app/modelos/login.interface';
import {Router} from '@angular/router'
import { CookieService } from 'ngx-cookie-service';
import {ResponseI} from'src/app/modelos/response.interface'

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  loginForm= new FormGroup({
    usuario: new FormControl('',Validators.required),
    password: new FormControl('',Validators.required)
  })

  constructor(private api:ApiService, private router:Router,private cookieS:CookieService) { }

  ngOnInit(): void {
  }

 onLogin(form:LoginI ){

 
  
  if(form.password=="admin" && form.usuario=="admin"){

    let admin:any={'result':{'nombre':'admin','password:':'admin'},'status':'ok'}

    console.log("el usuario es: "+form.password);
    console.log("el pass es: "+form.password);
    localStorage.setItem('token_acces',admin.result)
    
    this.router.navigate(['admin'])
  }else{

     // console.log(typeof(form))
    this.api.loginByEmail(form).subscribe(data=>{console.log(data);
    
       if(data.status== '200'){

        localStorage.setItem('token_user',JSON.stringify(data.result))
        this.router.navigate(['dashboard'])
     


       

       }else{

        alert("No se ha podico procesar la peticion")
       }
    
    })

  }

 }
}
