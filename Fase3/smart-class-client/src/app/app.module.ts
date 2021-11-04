import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { LoginComponent } from './vistas/login/login.component';
import { AdminComponent } from './vistas/admin/admin.component';
import { RegisterComponent } from './vistas/register/register.component';
import {ReactiveFormsModule,FormsModule} from '@angular/forms';
import {CookieService} from 'ngx-cookie-service';
import{HttpClientModule} from '@angular/common/http';
import { DashboardComponent } from './vistas/dashboard/dashboard.component';

@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    AdminComponent,
    RegisterComponent,
    DashboardComponent
   
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    FormsModule,
    HttpClientModule
  ],
  providers: [CookieService],
  bootstrap: [AppComponent]
})
export class AppModule { }
