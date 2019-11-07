<%@ Page Language="C#" MasterPageFile="~/PlacementMaster.Master" AutoEventWireup="true" CodeBehind="EventSchedule.aspx.cs" Inherits="Mini_Project.EventSchedule" %>

<asp:Content ID="Content2" ContentPlaceHolderID="headerContentPlaceHolder" runat="server"></asp:Content>

<asp:Content ID="Content1" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div class="container">
        <asp:GridView ID="GridView1" CssClass="table" runat="server" AutoGenerateColumns="False" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:TemplateField HeaderText="Company" SortExpression="Company">
                    <EditItemTemplate>
                        <asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("Company") %>'></asp:TextBox>
                    </EditItemTemplate>
                    <ItemTemplate>
                        <asp:LinkButton ID="LinkButton1" runat="server" Text='<%# Bind("Company") %>' OnClick="LinkButton1_Click"></asp:LinkButton>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:BoundField DataField="Event" HeaderText="Event" SortExpression="Event" />
                <asp:BoundField DataField="Date" HeaderText="Date" SortExpression="Date" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
            SelectCommand="SELECT * FROM [Schedules] ORDER BY [Date] DESC, [Company]"></asp:SqlDataSource>
    </div>
</asp:Content>

