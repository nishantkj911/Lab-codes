<%@ Page Language="C#"  MasterPageFile="~/Site2.Master" AutoEventWireup="true" CodeBehind="StudentDetails.aspx.cs" Inherits="DataBindingExample.StudentDetails" %>


<asp:Content runat="server" ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1">
    <form runat="server">

        Academic Information<br/><br/>

            <asp:GridView runat="server" ID="GV1" DataSourceID="SQ1"  BorderColor="#0000ff"  BorderWidth="2px" BorderStyle="Double" >
            <%--    <Columns>
                    <asp:BoundField HeaderText="Registration Number" DataField="Reg_No" />
                    <asp:BoundField HeaderText="X Std" DataField="X_Standard" />
                    <asp:BoundField HeaderText="XII Std" DataField="XII_Standard" />
                    <asp:BoundField HeaderText="Sem 1" DataField="Sem1" />
                    <asp:BoundField HeaderText="Sem 2" DataField="Sem2" />
                    <asp:BoundField HeaderText="Sem 3" DataField="Sem3" />
                    <asp:BoundField HeaderText="Sem 4" DataField="Sem4" />
                    <asp:BoundField HeaderText="Sem 5" DataField="Sem5" />
                    <asp:BoundField HeaderText="Sem 6" DataField="Sem6" />
                    <asp:BoundField HeaderText="CGPA" DataField="CGPA" />
                 </Columns>--%>
      
            </asp:GridView>
            <asp:SqlDataSource ID="SQ1" runat="server" connectionString="<%$connectionStrings:conStr %>"  SelectCommand="select * from Academic_Details where Reg_No=@Reg_No " >
               <SelectParameters>
                    <asp:SessionParameter SessionField="username" Name="Reg_No"  runat="server" />
                </SelectParameters>
            </asp:SqlDataSource>

        <br /><br />
        More Information<br /><br />
       <asp:GridView runat="server" ID="GV2" DataSourceID="SQ2" BorderColor="#0000ff"  BorderWidth="2px" BorderStyle="Double" >
        </asp:GridView>
        <asp:SqlDataSource ID="SQ2" runat="server"  connectionString="<%$connectionStrings:conStr %>" SelectCommand="select * from Extra_Details where Reg_No=@Reg_No">
           <SelectParameters>
                     <asp:SessionParameter SessionField="username" Name="Reg_No"  runat="server" />
            </SelectParameters>
        </asp:SqlDataSource>
 </form>   
</asp:Content>
