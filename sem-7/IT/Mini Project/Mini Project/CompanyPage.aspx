<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="CompanyPage.aspx.cs" Inherits="Mini_Project.CompanyPage" MasterPageFile="~/PlacementMaster.Master" %>

<asp:Content ID="Content1" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div>
        <asp:DetailsView ID="DetailsView1" runat="server" CssClass="table col-12 my-4 ml-4" DataSourceID="SqlDataSource1" DataKeyNames="Company" AutoGenerateRows="False">
            <Fields>
                <asp:BoundField DataField="Company" HeaderText="Company" ReadOnly="True" SortExpression="Company" />
                <asp:BoundField DataField="Eligible Branches" HeaderText="Eligible Branches" SortExpression="Eligible Branches" />
                <asp:BoundField DataField="CTC" HeaderText="CTC" SortExpression="CTC" />
                <asp:BoundField DataField="JobTitle" HeaderText="JobTitle" SortExpression="JobTitle" />
                <asp:BoundField DataField="JobDescription" HeaderText="JobDescription" SortExpression="JobDescription" />
            </Fields>
            <HeaderStyle Font-Bold="true" />
        </asp:DetailsView>
            <asp:SqlDataSource runat="server" ID="SqlDataSource1" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
                SelectCommand="SELECT * FROM [Companies] WHERE ([Company] = @Company)">
                <SelectParameters>
                    <asp:QueryStringParameter Name="Company" QueryStringField="companyName" Type="String" />
                </SelectParameters>
        </asp:SqlDataSource>
        <asp:LinkButton ID="RegisterButton" runat="server" OnClick="RegisterButton_Click">Register</asp:LinkButton>
    </div>
</asp:Content>
