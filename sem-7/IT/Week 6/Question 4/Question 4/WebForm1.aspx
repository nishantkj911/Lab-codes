<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="Question_4.WebForm1" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="headerPH" runat="server">
    This is header content
</asp:Content>

<asp:Content ID="Content4" ContentPlaceHolderID="leftPanel" runat="server">
    <asp:ListBox ID="ListBox1" runat="server">
        <asp:ListItem>Item1</asp:ListItem>
        <asp:ListItem>Item2</asp:ListItem>
        <asp:ListItem>Item3</asp:ListItem>
    </asp:ListBox>
</asp:Content>

<asp:Content ID="Content5" ContentPlaceHolderID="mainBody" runat="server">
    This is main body content
</asp:Content>

<asp:Content ID="Content6" ContentPlaceHolderID="footer" runat="server">
    <hr />
        This is footer content
</asp:Content>
