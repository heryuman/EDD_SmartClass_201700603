import { Injectable } from '@angular/core';
import {LoginI} from '../../modelos/login.interface';
import {ResponseI} from '../../modelos/response.interface';
import {HttpClient,HttpHeaders} from '@angular/common/http';
import { Observable } from 'rxjs';
import { RegisterI } from '../../modelos/register.interface';
import { MasivaI } from 'src/app/modelos/masiva.interface';
import { ApunteI } from 'src/app/modelos/apunte.inteface';
import { lista_apuntesI } from 'src/app/modelos/lista_apuntes.interface';

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

  masiveCursoEstudiant(form:MasivaI):Observable<ResponseI>{

    let dir=this.url+'cursosEstudiante'
    let obj_json=JSON.parse(form.dato_text_Area)
    return this.http.post<ResponseI>(dir,obj_json)
  }

  masiveApuntes(form:MasivaI):Observable<ResponseI>{

    let dir=this.url+'masivaApuntes'
    let obj_json=JSON.parse(form.dato_text_Area)
    
    return this.http.post<ResponseI>(dir,obj_json)

  }

  sendApunte(form:ApunteI):Observable<ResponseI>{

    let dir=this.url+'apunte'
    return this.http.post<ResponseI>(dir,form);
    
  }

  reprote0():Observable<ResponseI>{

    let dir=this.url+'reporte'
    let reporte0= JSON.parse('{\"tipo\":0}')

    return this.http.post<ResponseI>(dir,reporte0)

  }

  reprote5():Observable<ResponseI>{

    let dir=this.url+'reporte'
    let reporte0= JSON.parse('{\"tipo\":5}')

    return this.http.post<ResponseI>(dir,reporte0)

  }

  reporte6(){
    let dir=this.url+'reporte'
    let reprote6=JSON.parse('{\"tipo\":6}')

    return this.http.post<ResponseI>(dir,reprote6)
  }

  getListaApuntes(carnet:string):Observable<lista_apuntesI[]>{

    let dir=this.url+'getapunte'
    let headers=JSON.parse(`{"carnet":${carnet}}`)
 
    
    return this.http.post<lista_apuntesI[]>(dir,headers)


  }

}
