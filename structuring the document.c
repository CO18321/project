#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document doc;
    doc.data=NULL;
    doc.paragraph_count=0;
    char *parag_token;
    char *rest_doc=text;
    while((parag_token=__strtok_r(rest_doc,"\n",&rest_doc)))
    {
        if(doc.data==NULL)
        {
            doc.data=malloc(sizeof(struct paragraph));
        }
        else 
        {
            struct paragraph *parag_realloc;
            parag_realloc =realloc(doc.data,(doc.paragraph_count +1)*sizeof(struct paragraph ));
            if(parag_realloc!=NULL)
            {
                doc.data=parag_realloc;
            }
        }
        struct paragraph parag;
        parag.data=NULL;
        parag.sentence_count=0;
        char *sentence_token;
        char *rest_parag=parag_token;
        while((sentence_token=__strtok_r(rest_parag,".",&rest_parag)))
        {
            if(parag.data==NULL)
            {
                parag.data=malloc(sizeof(struct sentence));
            }
            else 
            {
                struct sentence *sent_realloc;
            sent_realloc=realloc(parag.data,(parag.sentence_count +1)*sizeof(struct sentence));
            if(sent_realloc!=NULL)
            {
                parag.data=sent_realloc;
            }
            }
            struct sentence sent;
            sent.data=NULL;
            sent.word_count=0;
            char *word_token;
            char *rest_sentence=sentence_token;
            while(word_token==__strtok_r(rest_sentence," ",&rest_sentence))
                {
                    if(sent.data==NULL)
                    {
                        sent.data=malloc(sizeof(struct word));
                    }
                    else
                    {
                        struct word *w_realloc;
                        w_realloc=realloc(sent.data,(sent.word_count +1)*sizeof(struct word));
                        if(w_realloc!=NULL)
                        {
                            sent.data=w_realloc;
                        }
                    }
                
                struct word w;
                w.data=malloc(strlen(word_token)*sizeof(char));
                strcpy(w.data,word_token);
                sent.data[sent.word_count]=w;
                sent.word_count++;
                }
             
         parag.data[parag.sentence_count]= sent;
         parag.sentence_count++; 
        }
        doc.data[doc.paragraph_count]=parag;
        doc.paragraph_count++;
    }
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];

}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];

}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];

}




void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
