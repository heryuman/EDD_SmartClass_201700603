import { Injectable } from '@angular/core';
import {LoginI} from '../../modelos/login.interface';
import {ResponseI} from '../../modelos/response.interface';
import {HttpClient,HttpHeaders} from '@angular/common/http';
import { Observable } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class ApiService {

  url:string="https://api.solodata.es/";
  constructor(private http:HttpClient) { }

  loginByEmail(form:LoginI):Observable<ResponseI>{

    let dir=this.url+"auth";
    return this.http.post<ResponseI>(dir,form);

  }
}
