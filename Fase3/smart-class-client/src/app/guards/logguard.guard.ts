import { Injectable } from '@angular/core';
import { ActivatedRouteSnapshot, CanActivate, Router, RouterStateSnapshot, UrlTree } from '@angular/router';
import { Observable } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class LogguardGuard implements CanActivate {


  constructor(private router:Router){}

  redirect(flag:any):boolean{

    if(flag ==null){

      this.router.navigate(['login'])
      return false
    }else{

      return true
    }
   
  }



  canActivate(
    route: ActivatedRouteSnapshot,
    state: RouterStateSnapshot): Observable<boolean | UrlTree> | Promise<boolean | UrlTree> | boolean | UrlTree {
    const localS=localStorage.getItem('token_acces')
    let redir=this.redirect(localS)
    
    return redir;
  }
  
}
