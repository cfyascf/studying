const clearButton = document.getElementById("clearButton")
clearButton.addEventListener("click", () => {
    const inputs = Array.from(document.querySelectorAll("input"))
    inputs.forEach((input) => input.value = "")
})