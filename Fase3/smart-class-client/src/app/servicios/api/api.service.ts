import { Injectable } from '@angular/core';
import {LoginI} from '../../modelos/login.interface';
import {ResponseI} from '../../modelos/response.interface';
import {HttpClient,HttpHeaders} from '@angular/common/http';
import { Observable } from 'rxjs';
import { RegisterI } from '../../modelos/register.interface';
import { MasivaI } from 'src/app/modelos/masiva.interface';


@Injectable({
  providedIn: 'root'
})
export class ApiService {

  url:string="http://localhost:3000/";
  constructor(private http:HttpClient) { }



  loginByEmail(form:LoginI):Observable<ResponseI>{

    let dir=this.url+"estudiante";
 
    return this.http.post<ResponseI>(dir,form);

  }

  registerUser(form:RegisterI):Observable<ResponseI>{


    let dir= this.url+'registro';
    
    return this.http.post<ResponseI>(dir,form);
  }

  masiveUsers(form:MasivaI):Observable<ResponseI>{

    let dir=this.url+'masivaEstudiantes'
    let obj_json=JSON.parse(form.dato_text_Area)

    return this.http.post<ResponseI>(dir,obj_json)

  }

  masivePensum(form:MasivaI):Observable<ResponseI>{

    let dir=this.url+'cursosPensum'
    let obj_json=JSON.parse(form.dato_text_Area)

    return this.http.post<ResponseI>(dir,obj_json);

  }

  reprote0():Observable<ResponseI>{

    let dir=this.url+'reporte'
    let reporte0= JSON.parse('{\"tipo\":0}')

    return this.http.post<ResponseI>(dir,reporte0)

  }
}
