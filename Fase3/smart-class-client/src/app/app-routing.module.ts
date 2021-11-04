import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import {LoginComponent} from './vistas/login/login.component';
import {AdminComponent} from './vistas/admin/admin.component';
import {RegisterComponent} from './vistas/register/register.component';
import { LogguardGuard } from './guards/logguard.guard';
import {DashboardComponent}from './vistas/dashboard/dashboard.component'

const routes: Routes = [

  {path:'',redirectTo:'login',pathMatch:'full'},
  {path:'login',component:LoginComponent},
  {path:'admin',component:AdminComponent,canActivate:[LogguardGuard]},
  {path:'register',component:RegisterComponent},
  {path:'dashboard',component:DashboardComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
