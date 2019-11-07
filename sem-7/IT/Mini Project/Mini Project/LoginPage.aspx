<%@ Page Title="Login Page" Language="C#" MasterPageFile="~/PlacementMaster.Master" AutoEventWireup="true" CodeBehind="LoginPage.aspx.cs" Inherits="Mini_Project.LoginPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headerContentPlaceHolder" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div id="tabs">
        <ul class="nav nav-tabs">
            <li class="active"><a href="#studentLogin" data-toggle="tab">Student</a></li>
            <li><a href="#adminLogin" data-toggle="tab">Admin</a></li>
        </ul>
        <div class="tab-content">
            <div id="studentLogin" class="tab-pane active">
                <div class="table">
                    <div class="row">
                        <div class="col-2">
                            Registration No.
                        </div>
                        <div class="col-10">
                            <asp:TextBox ID="RegNoTB" runat="server"></asp:TextBox>
                            <asp:RequiredFieldValidator CssClass="text-danger" ErrorMessage="Reg. No. field is Mandatory" ControlToValidate="RegNoTB" runat="server" ID="RegNoValidator" ValidationGroup="Login" />
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-2">
                            Password
                        </div>
                        <div class="col-10">
                            <asp:TextBox ID="PasswordTB" runat="server" TextMode="Password"></asp:TextBox>
                            <asp:RequiredFieldValidator CssClass="text-danger" ErrorMessage="Password Field is Mandatory" ControlToValidate="PasswordTB" runat="server" ID="PasswordValidator" ValidationGroup="Login" />
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-12">
                            <asp:Button ID="LoginButton" OnClick="LoginButton_Click" runat="server" Text="Login" ValidationGroup="Login" />
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-3">
                            <asp:Label ID="Label1" runat="server" Text="Don't have an account?"></asp:Label>
                        </div>
                        <div class="col-8">
                            <asp:Button ID="RegisterButton" runat="server" Text="Register" OnClick="RegisterButton_Click" />
                        </div>
                    </div>
                </div>
            </div>
            <div id="adminLogin" class="tab-pane">
                Admin Login
            </div>
        </div>

    </div>
</asp:Content>
