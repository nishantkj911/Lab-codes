<%@ Page Language="C#"  MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="Placement.Login" %>

<asp:Content runat="server" ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1">
    <form runat="server">
        <div class="form-group" style="margin-bottom:20px;margin-top:40px">
            <label >User Name:</label>
            <asp:TextBox runat="server" id="usr"  placeholder="Enter Username" width="30%" /><asp:RequiredFieldValidator id="vali1" enabled="false" runat="server" ControlToValidate="usr" ErrorMessage="Please enter username"></asp:RequiredFieldValidator>

        </div>
        <div class="form-group">
            <label >Password:</label>
            <asp:TextBox runat="server" id="pwd"  placeholder="Enter Password" width="30%"/><asp:RequiredFieldValidator ID="vali2" Enabled="false" runat="server" ControlToValidate="pwd" ErrorMessage="Please enter password"></asp:RequiredFieldValidator>
         
        </div>
        <div class="container-fluid" style="margin-bottom:20px">
            <div class="row">
                <div class="col-lg-2">
                    <asp:Button ID="Sign_In" runat="server" Text="Login" OnClick="Login_Click" />
                </div>
                <div class="col-lg-2">
                    <asp:Button ID="Register" runat="server" Text="Register" OnClick="Register_Click" />
                </div>
            </div>
        </div>
        </form>    
 </asp:Content>


