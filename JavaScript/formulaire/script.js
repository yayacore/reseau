console.log("test");

const form = document.querySelector("form");    //récup les attributs de l'elmnt HTML "form"

form.addEventListener("submit",onLogin);    //écoute sur le submit (le bouton)

function onLogin(event){
    event.preventDefault(); //désactive le comportement par default de l'évenement grâce à la fonction preventDefault() pr la vérification des champs du formulaire
    const formData = new FormData(event.target);
    
    /**
     * ici ça print ds la console les données que l'utilisateur 
     * a saisi dans les champs du formulaire
     */
    console.log(formData);
    console.log(formData.get("nom"));
    console.log(formData.get("prenom"));
    console.log(formData.get("mail"));
    console.log(formData.get("message"));

    /**
     * conditions pr que les champs soient valides
     */

    if(nom.length < 2 || nom.length > 20) {
        console.log("erreur lors de la saisie du nom");
        return false;
    }

    if(prenom.length < 2 || prenom.length > 20) {
        console.log("erreur lors de la saisie du prénom");
        return false;
    }

    if(prenom.length < 2 || prenom.length > 20) {
        console.log("erreur lors de la saisie du prénom");
        return false;
    }

    if(message.length > 100 || message.length < 10){
        console.log("erreur lors de la saisie de votre message");
        return false;
    }

    const emailFormat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/; // Création d'un objet RegexExp (vérifier qu'une adresse mail est valide)
    
    if(emailFormat.test(email)){
        return true;
    }else{
        return false
    }


}