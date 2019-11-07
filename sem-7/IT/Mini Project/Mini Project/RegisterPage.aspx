<%@ Page Title="" Language="C#" MasterPageFile="~/PlacementMaster.Master" AutoEventWireup="true" CodeBehind="RegisterPage.aspx.cs" Inherits="Mini_Project.RegisterPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headerContentPlaceHolder" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div class="table">
        <div class="row">
            <div class="col-2">
                <asp:Label ID="RegNoLabel" runat="server" Text="Registration No."></asp:Label>
            </div>
            <div class="col-10">
                <asp:TextBox ID="RegNoTB" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="RegNoValidator" runat="server" ErrorMessage="Registration No. is mandatory" ControlToValidate="RegNoTB" SkinID="reqFieldValidator" CssClass="text-danger"></asp:RequiredFieldValidator>
            </div>
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="FirstNameLabel" runat="server" Text="First Name"></asp:Label>
            </div>
            <div class="col-10">
                <asp:TextBox ID="FirstNameTB" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="FirstNameValidator" runat="server" ErrorMessage="First Name is mandatory" ControlToValidate="FirstNameTB" CssClass="text-danger"></asp:RequiredFieldValidator>
            </div>
            <br />
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="MiddleNameLabel" runat="server" Text="Middle Name"></asp:Label>
            </div>
            <div class="col-2">
                <asp:TextBox ID="MiddleNameTB" runat="server"></asp:TextBox>
            </div>
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="LastNameLabel" runat="server" Text="Last Name"></asp:Label>
            </div>
            <div class="col-2">
                <asp:TextBox ID="LastNameTB" runat="server"></asp:TextBox>
            </div>
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="DOBLabel" runat="server" Text="Date Of Birth"></asp:Label>
            </div>
            <div class="col-10">
                <asp:TextBox ID="DOBTB" runat="server"></asp:TextBox>
                <asp:RequiredFieldValidator ID="DOBValidator" runat="server" ErrorMessage="DOB is mandatory" CssClass="text-danger" ControlToValidate="DOBTB"></asp:RequiredFieldValidator>
            </div>
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="BranchLabel" runat="server" Text="Branch"></asp:Label>
            </div>
            <div class="col-10">
                <asp:DropDownList ID="BranchDDL" runat="server" DataSourceID="SqlDataSource2" DataTextField="BranchName" DataValueField="BranchID"></asp:DropDownList>
                <asp:SqlDataSource runat="server" ID="SqlDataSource2" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" SelectCommand="SELECT * FROM [Branches]"/>
            </div>
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="Password1Label" runat="server" Text="Enter a Password"></asp:Label>
            </div>
            <div class="col-10">
                <asp:TextBox ID="Password1TB" runat="server" TextMode="Password"></asp:TextBox>
                <asp:RequiredFieldValidator ID="PasswordValidator" runat="server" ErrorMessage="Password Field 1 is mandatory" ControlToValidate="Password1TB" CssClass="text-danger"></asp:RequiredFieldValidator>
            </div>
        </div>
        <div class="row">
            <div class="col-2">
                <asp:Label ID="Password2Label" runat="server" Text="Confirm Password"></asp:Label>
            </div>
            <div class="col-10">
                <asp:TextBox ID="Password2TB" runat="server" TextMode="Password"></asp:TextBox>
                <asp:RequiredFieldValidator ID="PasswordValidator2" runat="server" ErrorMessage="Password Field 2 is mandatory" ControlToValidate="Password2TB" CssClass="text-danger"></asp:RequiredFieldValidator>
            </div>
        </div>
        <div class="row">
            <div class="col-4">
                <asp:Button ID="RegisterButton" runat="server" Text="Register" OnClick="RegisterButton_Click" />
            </div>
            <div class="col-8">
                <asp:CompareValidator ID="PasswordCompareValidator" runat="server" ErrorMessage="The passwords do not match" CssClass="text-danger" ControlToCompare="Password2TB" ControlToValidate="Password1TB"></asp:CompareValidator>
                <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False"
                    InsertCommand="INSERT INTO [Students] ([Regno], [FirstName], [MiddleName], [LastName], [DOB], [loginPassword], [Branch]) VALUES (@Regno, @FirstName, @MiddleName, @LastName, @DOB, @loginPassword, @Branch)" 
                    ProviderName="System.Data.SqlClient" DeleteCommand="DELETE FROM [Students] WHERE [Regno] = @Regno" SelectCommand="SELECT * FROM [Students]" UpdateCommand="UPDATE [Students] SET [FirstName] = @FirstName, [MiddleName] = @MiddleName, [LastName] = @LastName, [DOB] = @DOB, [loginPassword] = @loginPassword, [Branch] = @Branch WHERE [Regno] = @Regno">
                </asp:SqlDataSource>
            </div>
        </div>
    </div>
</asp:Content>
