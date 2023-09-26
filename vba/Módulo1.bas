Attribute VB_Name = "Módulo1"
Sub adicionarColaborador()

    Dim linhas, id, age As Integer
    Dim name, gender, companyArea As String
    
    linhas = Sheets("Customer").Range("B10000").End(xlUp).Row
    
    id = Int(10000 * Rnd)
    name = Sheets("Manage").Range("B4").Value
    age = Sheets("Manage").Range("C4").Value
    gender = Sheets("Manage").Range("D4").Value
    companyArea = Sheets("Manage").Range("E4").Value
    
    Sheets("Customer").Cells(linhas + 1, 2).Value = id
    Sheets("Customer").Cells(linhas + 1, 3).Value = name
    Sheets("Customer").Cells(linhas + 1, 4).Value = age
    Sheets("Customer").Cells(linhas + 1, 5).Value = gender
    Sheets("Customer").Cells(linhas + 1, 6).Value = companyArea
    Sheets("Manage").Range("B4:E4").Delete
    
End Sub
