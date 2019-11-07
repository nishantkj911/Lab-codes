<%@ Page Title="" Language="C#" MasterPageFile="~/PlacementMaster.Master" AutoEventWireup="true" CodeBehind="StudentProfile.aspx.cs" Inherits="Mini_Project.StudentProfile" %>

<asp:Content ID="Content1" ContentPlaceHolderID="headerContentPlaceHolder" runat="server">
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="bodyPlaceholder1" runat="server">
    <div class="container bg-light">
        <div class="row">
            <div id="para" class="h3 col-6" runat="server"></div>
            <div class="col-6 h4">
                Student Details
            </div>
        </div>
        <asp:FormView ID="FormView1" runat="server" DataKeyNames="Regno" DataSourceID="SqlDataSource1">
            <EditItemTemplate>
                <div class="table">
                    <div class="row">
                        <div class="col font-weight-bold">
                            First Name:
                        </div>
                        <div class="col">
                            <asp:TextBox ID="FirstNameTextBox" runat="server" Text='<%# Bind("FirstName") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            Middle Name:
                        </div>
                        <div class="col">
                            <asp:TextBox ID="MiddleNameTextBox" runat="server" Text='<%# Bind("MiddleName") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            Last Name:
                        </div>
                        <div class="col">
                            <asp:TextBox ID="LastNameTextBox" runat="server" Text='<%# Bind("LastName") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            DOB:
                        </div>
                        <div class="col">
                            <asp:TextBox ID="DOBTextBox" runat="server" Text='<%# Bind("DOB") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            Branch:
                        </div>
                        <div class="col">
                            <asp:TextBox ID="BranchTextBox" runat="server" Text='<%# Bind("Branch") %>' />
                        </div>
                    </div>
                </div>
                <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" CommandName="Update" Text="Update" />
                &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel" />
            </EditItemTemplate>
            <InsertItemTemplate>
                Regno:
                <asp:TextBox ID="RegnoTextBox" runat="server" Text='<%# Bind("Regno") %>' />
                <br />
                FirstName:
                <asp:TextBox ID="FirstNameTextBox" runat="server" Text='<%# Bind("FirstName") %>' />
                <br />
                MiddleName:
                <asp:TextBox ID="MiddleNameTextBox" runat="server" Text='<%# Bind("MiddleName") %>' />
                <br />
                LastName:
                <asp:TextBox ID="LastNameTextBox" runat="server" Text='<%# Bind("LastName") %>' />
                <br />
                DOB:
                <asp:TextBox ID="DOBTextBox" runat="server" Text='<%# Bind("DOB") %>' />
                <br />
                Branch:
                <asp:TextBox ID="BranchTextBox" runat="server" Text='<%# Bind("Branch") %>' />
                <br />
                <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" CommandName="Insert" Text="Insert" />
                &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" CausesValidation="False" CommandName="Cancel" Text="Cancel" />
            </InsertItemTemplate>
            <ItemTemplate>
                <div class="table">
                    <div class="row">
                        <div class="col font-weight-bold">
                            First Name:
                        </div>
                        <div class="col">
                            <asp:Label ID="FirstNameLabel" runat="server" Text='<%# Bind("FirstName") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            Middle Name:
                        </div>
                        <div class="col">
                            <asp:Label ID="MiddleNameLabel" runat="server" Text='<%# Bind("MiddleName") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            Last Name:
                        </div>
                        <div class="col">
                            <asp:Label ID="LastNameLabel" runat="server" Text='<%# Bind("LastName") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            DOB:
                        </div>
                        <div class="col">
                            <asp:Label ID="DOBLabel" runat="server" Text='<%# Bind("DOB") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col font-weight-bold">
                            Branch:
                        </div>
                        <div class="col">
                            <asp:Label ID="BranchLabel" runat="server" Text='<%# Bind("Branch") %>' />
                        </div>
                    </div>

                    <div class="row">
                        <div class="col">
                            <asp:LinkButton ID="EditLinkButton" CommandName="Edit" CommandArgument="Edit" runat="server" Text="Edit" ></asp:LinkButton>
                        </div>
                    </div>
                </div>
            </ItemTemplate>
        </asp:FormView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="Data Source=(localdb)\MSSQLlocalDB;Initial Catalog=MiniProject;Integrated Security=True;Pooling=False" ProviderName="System.Data.SqlClient" 
            SelectCommand="SELECT * FROM [Students] WHERE ([Regno] = @Regno)" 
            DeleteCommand="DELETE FROM [Students] WHERE [Regno] = @Regno" 
            InsertCommand="INSERT INTO [Students] ([Regno], [FirstName], [MiddleName], [LastName], [DOB], [loginPassword], [Branch]) VALUES (@Regno, @FirstName, @MiddleName, @LastName, @DOB, @Branch)" 
            UpdateCommand="UPDATE [Students] SET [FirstName] = @FirstName, [MiddleName] = @MiddleName, [LastName] = @LastName, [DOB] = @DOB, [Branch] = @Branch WHERE [Regno] = @Regno">
            <DeleteParameters>
                <asp:Parameter Name="Regno" Type="Int32" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="Regno" Type="Int32" />
                <asp:Parameter Name="FirstName" Type="String" />
                <asp:Parameter Name="MiddleName" Type="String" />
                <asp:Parameter Name="LastName" Type="String" />
                <asp:Parameter DbType="Date" Name="DOB" />
                <asp:Parameter Name="Branch" Type="String" />
            </InsertParameters>
            <SelectParameters>
                <asp:SessionParameter Name="Regno" SessionField="Regno" Type="Int32" />
            </SelectParameters>
            <UpdateParameters>
                <asp:Parameter Name="FirstName" Type="String" />
                <asp:Parameter Name="MiddleName" Type="String" />
                <asp:Parameter Name="LastName" Type="String" />
                <asp:Parameter DbType="Date" Name="DOB" />
                <asp:Parameter Name="Branch" Type="String" />
                <asp:Parameter Name="Regno" Type="Int32" />
            </UpdateParameters>
        </asp:SqlDataSource>
    </div>
</asp:Content>
